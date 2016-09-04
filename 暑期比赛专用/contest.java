import java.util.Scanner;
import java.math.BigInteger;
import java.io.BufferedInputStream;

public class Main{
	private static BigInteger two = BigInteger.valueOf(2);
	public int f(int a){
		return (a < 0 ? -a : a);
	}
	public static void main(String[] args){
		Scanner in = new Scanner(new BufferedInputStream(System.in));
		
		int n = in.nextInt();
		int k = in.nextInt();

		int val = 0;
		BigInteger sum = BigInteger.ZERO;
		BigInteger b[] = new BigInteger[n];
		b[0] = BigInteger.ONE;
		for ( int i = 0; i <= n; ++i) {
			val = in.nextInt();
			
			sum = sum.add(b[i].multiply(BigInteger.valueOf(val)));
			if(i == 0) b[i] = b[i-1].multiply(two);
		}

		int ans = 0;
		for(int i = 0; i <= n; ++i){
			if(sum.mod(b[i]).equals(BigInteger.ZERO)){
				int tmp = sum.divide(b[i]).intValue();
				if(f(tmp) <= k) ++ans;
			}
		}
		System.out.println(tmp);
	}
}