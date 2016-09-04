import java.util.Scanner;
import java.io.BufferedInputStream;
import java.math.BigInteger;

public class Main{
    private static Scanner in;
    public static void main(String[] args){
        in = new Scanner(new BufferedInputStream(System.in));
        
        while(in.hasNext()){
            int n = in.nextInt();
            BigInteger tmp = BigInteger.ONE;
            for(int i = 2; i <= 2 * n; ++i){
                tmp = tmp.multiply(BigInteger.valueOf(i));
            }
            for(int i = 2; i <= n; ++i){
                tmp = tmp.divide(BigInteger.valueOf(i));
                tmp = tmp.divide(BigInteger.valueOf(i));
            }
            tmp = tmp.divide(BigInteger.valueOf(n + 1));
            System.out.println(tmp);
        }
    }
}