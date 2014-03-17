import java.math.BigInteger;


public class Butter {

	public static void main(String[] args) {
		
		BigInteger fiboPrev = new BigInteger(0 + "");
		BigInteger fiboNext = new BigInteger(1 + "");
		BigInteger sum = new BigInteger(0+"");
		BigInteger mP = new BigInteger("2");
		BigInteger mN = BigInteger.ZERO;
		BigInteger mul = new BigInteger("1");
		
		for(int i=2;i<514;i++) {
			
			if(i%2 == 0) {
			mN = fiboNext.multiply(new BigInteger("5")).subtract(mP);
			
			if((i&(i-1)) == 0) {
				System.out.println(i + " " + mN);
				mul = mul.multiply(mN).mod(new BigInteger("1000000007"));
			}
			
			mP = mN;
			}
			sum = fiboPrev.add(fiboNext);
			fiboPrev = fiboNext;
			fiboNext = sum;
		}
		
		System.out.println("sol: "+mul);
		
		
	}

}
/**
 * 	2 3
 *  4 7
 *  8 47
 *  16 2207
 *  32 4870847
 *	64 23725150497407
 *	128 562882766124611619513723647
 *	256 316837008400094222150776738483768236006420971486980607
 *	512 100385689891921376688754239992826256704879627683181901515099398613465618884806971304035121947368905594088447
	
	sol: 754854590
 */


