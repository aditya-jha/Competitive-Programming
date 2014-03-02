import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
 
public class Main {
	
	public static void sieve(boolean prime[]) {
		for(int i=0;i<100010;i++) prime[i] = true;
		prime[0] = prime[1] = false;
    
    	double lim = Math.ceil(Math.sqrt(100010));
		for(int i=2;i<=lim;i++) {
			if(prime[i]) {
				for(int j=i*i;j<=100010;j+=i) { //i*i may not be able to hold int, check will solving questions
					prime[j]=false;				
				}
			}
		}
	}
	
	public static long factors(int n, int p)  {
    	int count = 0;
    	while(n>=p) {
        	n = n/p;
        	count += n; 
    	}    
    	return count;
	} 
	
	public static int solve(int n, long b, int prime[]) {
		BigInteger mul = new BigInteger("1");
		
				
		for(int i=2;i<=n; i++) {
			String temp = "",tt="";
			temp += i;
			if(prime[i] == true) {
				tt += factors(n,i);
				mul *= new BigInteger(temp).pow(tt);
			}
		}
		
		String temp = "";
		temp += b;
		BigInteger div = mul.divide(new BigInteger(temp));
		long count = div.longValue();
		
		if(count%2 == 0) return 1;
		else return 0;
	}
	 
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		
		boolean prime[] = new boolean[100010];
		for(int i=2;i<100010;i++) prime[i] = true;
		
		sieve(prime);
		
		String test;
		int n;
		long b;
		
		int t = Integer.parseInt(br.readLine());
		
		while(t>0) {
			
			test=br.readLine();
	   		String k[]= test.split(" ");
			n =Integer.parseInt(k[0]);
			b =Integer.parseInt(k[1]);
			
			if(Main.solve(n,b,prime) == 1) System.out.println("Even");
			else System.out.println("Odd");
			
			t--;
		}
	}
} 
