import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;

/* Name of the class has to be "Main" only if the class is public. */
class Ideone
{
	public static void main (String[] args) throws java.lang.Exception
	{
		BigInteger a,b,c;
		String x,y;
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int t=10;
		
		while(t>0) {
			t = t-1;
			x = br.readLine();
			y = br.readLine();
			
			a = new BigInteger(x);
			b = new BigInteger(y);
			
			c = a.subtract(b);
			
			a = c.divide(new BigInteger("2"));
			
			System.out.println(a.add(b));
			System.out.println(a);
		}
	}
}