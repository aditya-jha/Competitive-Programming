public class SumThemAll {
   
   static long dp[][] = new long[10][11];

   long f(int x) {
      String s;
      long ret, z;
      int i, j, k, y;

      s = Integer.valueOf(x).toString();
      z = 1;
      for (j = 1; j < s.length(); j++) z *= 10;
      ret = 0;
      y = 0;
      for (j = 0; j < s.length(); j++) {
         k = s.charAt(j) - '0';
         for (i = 0; i < k; i++) ret += dp[i][s.length() - j] + y * z;
         y += k;     // Add just treatend digit to y
         z /= 10;
      }
      return ret;
   }
   
   public long getSum(int lowerBound, int upperBound) {
      long k;
      int i, j;
      for (i = 0; i < 10; i++) dp[i][0] = 0;
      k = 1;
      for (j = 1; j < 11; j++) {
         dp[0][j] = 0;
         for (i = 0; i < 10; i++) dp[0][j] += dp[i][j - 1];  
         // dp[0][j] contains the sum of all the numbers,
         // which have less than j digits
         // (like they can be precedeed with extra leading zero(s))
         for (i = 0; i < 10; i++) dp[i][j] = dp[0][j] + k * i;
         k *= 10;
      }
      return f(upperBound + 1) - f(lowerBound);
   }
