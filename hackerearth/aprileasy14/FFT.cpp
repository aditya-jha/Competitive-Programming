#include <inttypes.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef N
#define N 1000000
#endif
#define BASE 10000
#define LOG10_BASE 4

#define FFT_DIRECT 1
#define FFT_INVERSE -1

typedef struct bi_double {
double *digits; //(Big-Endian) Uso i double per evitare overhead quando devo calcolare la FFT
size_t len; // Il numero di cifre in base BASE, sono sempre una potenza di 2
size_t last; // L'indice della cifra più significativa
} bigUint;

/* Calcola il numero di digits in base BASE per il numero val, arrotondando alla potenza di due più piccola che possa contenerlo */
static size_t get_digits(uint64_t val) {
if (val <= (uint64_t) BASE)
return (size_t) 2;
size_t pow = 1;
size_t ret = (size_t) ceil(ceil(log10(val)) / (double) LOG10_BASE);
if ((ret & (ret - 1)) != 0) {
while (pow < ret)
pow <<= 1;
ret = pow;
}
return ret;
}

/* Coi parametri attuali la funzione è semplicemente questa */
/*static size_t get_digits(uint64_t val) {
return ( val < (uint64_t)BASE)?2:4;
}*/

/* Ingrandisce a in modo che sia capace di contenere size digits, mantenendo l'invariante della potenza di due */
static void m_set_size(bigUint* a, size_t size) {
size_t p2size = 1;
size_t i;
double *d = a->digits;
if ((size & (size - 1)) != 0) {
do {
p2size <<= 1;
} while (p2size < size);
size = p2size;
}
a->digits = malloc(sizeof(double) * size);
memset((void*) a->digits, 0, sizeof(double) * size);
for (i = 0; i <= a->last; i++)
a->digits[i] = d[i];
free(d);
a->len = size;
}

/** Svolge i riporti in base BASE. Ritorna l'indice dell'ultimo elemento significativo*/
static size_t docarry(bigUint* a) {
size_t i = 0, llen = a->len;
uint64_t carry = 0;
uint64_t rounda = 0;
double *larr = a->digits;

for (i = 0; i < llen; i++) {
rounda = ((uint64_t) round(larr[i])) + carry;
carry = rounda / BASE;
larr[i] = (double) (rounda % BASE);
}
while (carry != 0) {
if (i == llen) {
llen <<= 1;
m_set_size(a, llen);
}
rounda = ((uint64_t) round(larr[i])) + carry;
carry = rounda / BASE;
larr[i] = (double) (rounda % BASE);
}
i = llen - 1;
while (larr[i] == 0)
i--;
return i;
}

/* Rappresenta val come un polinomio in base BASE. arr deve avere spazio sufficiente per contenerlo */
static size_t set_arr(double* arr, uint64_t val) {
size_t i = 0;

do {
arr[i] = (double) (val % (uint64_t) BASE);
val /= BASE;
i++;
} while (val != 0);
return i - 1;
}

/* Alloca un nuovo bigUint, inizializzandolo con il valore di val */
bigUint* m_alloc(uint64_t val) {

bigUint* ret = malloc(sizeof(bigUint));
ret->len = get_digits(val);
ret->digits = malloc(sizeof(double) * (ret->len));

memset(ret->digits, 0, sizeof(double) * ret->len);
ret->last = set_arr(ret->digits, val);

return ret;
}

/* NUMERICAL RECIPES 3rd EDITION */
static void four1(double *data, size_t n, int transform) {

int mmax, m, j, istep, i, isign;
double wtemp, wr, wpr, wpi, wi, theta, tempi, tempr;
double temp;
/*(transform == FFT_DIRECT) ? 1 : -1;*/
/* ^ L'ho levato perché FFT_DIRECT = 1 e FFT_INVERSE = -1*/
isign = transform;
j = 1;

for (i = 1; i < n; i += 2) {
if (j > i) {
temp = data[j - 1];
data[j - 1] = data[i - 1];
data[i - 1] = temp;
temp = data[j];
data[j] = data[i];
data[i] = temp;
}
m = n >> 1;
while (m >= 2 && j > m) {
j -= m;
m >>= 1;
}
j += m;
}
mmax = 2;

while (n > mmax) {
istep = mmax << 1;
theta = isign * (2 * M_PI / mmax);
wtemp = sin(0.5 * theta);
wpr = -2.0 * wtemp * wtemp;
wpi = sin(theta);
wr = 1.0;
wi = 0.0;
for (m = 1; m < mmax; m += 2) {
for (i = m; i <= n; i += istep) {
j = i + mmax;
tempr = wr * data[j - 1] - wi * data[j];
tempi = wr * data[j] + wi * data[j - 1];
data[j - 1] = (data[i - 1] - tempr);
data[j] = (data[i] - tempi);
data[i - 1] = (data[i - 1] + tempr);
data[i] = (data[i] + tempi);
}
wr = (wtemp = wr) * wpr - wi * wpi + wr;
wi = wi * wpr + wtemp * wpi + wi;
}
mmax = istep;
}

}

/* NUMERICAL RECIPES 3rd EDITION */
static void realFFT(double *data, size_t n, int transform) {
int i, i1, i2, i3, i4, np3;
double wr, wi, wpr, wpi, wtemp, theta, c1 = 0.5, c2, h1r, h1i, h2r, h2i;

theta = M_PI / (n >> 1);
if (transform == FFT_DIRECT) {
c2 = -0.5;
four1(data, n, FFT_DIRECT);
} else {
c2 = 0.5;
theta = -theta;
}

wtemp = sin(0.5 * theta);
wpr = -2.0 * wtemp * wtemp;
wpi = sin(theta);
wr = 1.0 + wpr;
wi = wpi;
np3 = n + 3;

for (i = 2; i <= (n >> 2); i++) {
i4 = 1 + (i3 = np3 - (i2 = 1 + (i1 = i + i - 1)));
h1r = c1 * (data[i1 - 1] + data[i3 - 1]);
h1i = c1 * (data[i2 - 1] - data[i4 - 1]);
h2r = -c2 * (data[i2 - 1] + data[i4 - 1]);
h2i = c2 * (data[i1 - 1] - data[i3 - 1]);
data[i1 - 1] = (h1r + wr * h2r - wi * h2i);
data[i2 - 1] = (h1i + wr * h2i + wi * h2r);
data[i3 - 1] = (h1r - wr * h2r + wi * h2i);
data[i4 - 1] = (-h1i + wr * h2i + wi * h2r);
wr = (wtemp = wr) * wpr - wi * wpi + wr;
wi = wi * wpr + wtemp * wpi + wi;
}

if (transform == FFT_DIRECT) {
data[0] = ((h1r = data[0]) + data[1]);
data[1] = (h1r - data[1]);
for (i = 0; i < n; i++) {
data[i] = (data[i] / sqrt((double) n));
}
} else {
data[0] = (c1 * ((h1r = data[0]) + data[1]));
data[1] = (c1 * (h1r - data[1]));
four1(data, n, FFT_INVERSE);
for (i = 0; i < n; i++) {
data[i] = (2 * data[i] / sqrt((double) n));
}

}

}

/* Dealloca il bigUint */
void m_free(bigUint **a) {

free((*a)->digits);
free((*a));

}

/*
privstatic BigInt simpleMultiply(BigInt val1, BigInt val2) {
if (val1.A.length < val2.A.length) return simpleMultiply(val2, val1); int[] acc = new int[val1.A.length + val2.A.length];
for (int k = 0; k < val2.A.length; k++)
for (int i = 0; i < val1.A.length; i++) acc[i + k] += val1.A[i] * val2.A[k];
BigInt res = new BigInt(propagateCarries(acc));
return res; }
*/

#define DIGITS_LIMIT 200
void m_print(bigUint *a);

bigUint* short_m_mul(bigUint *a, bigUint *b) {
double *acc;
double *dmp;
size_t i, k;
size_t mulsize;
if (a->last < b->last)
return short_m_mul(b, a);
mulsize = (a->last + b->last + 2);
acc = malloc(mulsize * sizeof(double));
memset((void*) acc, 0, (sizeof(double) * mulsize));

for (k = 0; k <= b->last; k++)
for (i = 0; i <= a->last; i++)
acc[i + k] += (a->digits[i] * b->digits[k]);
dmp = a->digits;
free(dmp);
a->digits = acc;
a->len = mulsize;
a->last = docarry(a);
m_free(&b);
return a;
}

/* Calcola a*b, torna il risultato ed elimina dalla memoria b */
bigUint* m_mul(bigUint* a, bigUint* b) {

bigUint *max;
bigUint *min;
size_t n;
size_t i;
double c, ai, ai1;

if (a->last < DIGITS_LIMIT || b->last < DIGITS_LIMIT)
return short_m_mul(a, b);

max = ((a->last > b->last) ? a : b);
min = ((max == a) ? b : a);
n = max->len;
/* Passo a numeri con un numero di digits potenza di due */
if ((n & (n - 1)) != 0) {
i = 1;
while (i < n)
i <<= 1;
n = i;
}

/* Controllo se il più lungo può contenere il prodotto*/
if ((max->len - max->last) <= min->last + 1) {
n = n << 1;
}
if (a->len != n)
m_set_size(a, n);
if (b->len != n)
m_set_size(b, n);

realFFT(a->digits, n, FFT_DIRECT);
realFFT(b->digits, n, FFT_DIRECT);
c = sqrt(n);
a->digits[0] *= (c * b->digits[0]);
a->digits[1] *= (c * b->digits[1]);
for (i = 2; i < n; i += 2) {
ai = c * a->digits[i], ai1 = c * a->digits[i + 1];
a->digits[i] = ai * b->digits[i] - ai1 * b->digits[i + 1];
a->digits[i + 1] = ai1 * b->digits[i] + ai * b->digits[i + 1];
}

m_free(&b);
realFFT(a->digits, n, FFT_INVERSE);
a->last = docarry(a);
return a;
}

/* Stampa a in base BASE */
void m_print(bigUint *a) {

size_t i;
fprintf(stdout, "%"PRIu64, (uint64_t) a->digits[a->last]);
if (a->last > 0) {
for (i = a->last - 1; i > 0; i--)
fprintf(stdout, "%0*"PRIu64, LOG10_BASE, (uint64_t) a->digits[i]);
fprintf(stdout, "%0*"PRIu64, LOG10_BASE, (uint64_t) a->digits[0]);
}
fflush(stdout);
}

/* Binary Split */
bigUint* Q(uint64_t a, uint64_t b) {
uint64_t m;
if ((b - a) == 1)
return m_alloc(b);
m = (a + b) / 2;
return m_mul(Q(a, m), Q(m, b));
}

int main(int argc, char* argv[]) {

m_print(Q(0, N));

return 0;
}
