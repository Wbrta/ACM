import java.util.Scanner;
import java.io.BufferedInputStream;
import java.math.BigInteger;

public class Main{
    private static Scanner in;
    private static BigInteger fib[] = new BigInteger[10000 + 5];
    
    public static void initFib(){
    	fib[0] = BigInteger.ZERO;
        fib[1] = BigInteger.ONE;
        fib[2] = BigInteger.ONE;
        fib[3] = BigInteger.ONE;
        fib[4] = BigInteger.ONE;
        for(int i = 5; i < 10005; ++i){
            fib[i] = fib[i-1].add(fib[i-2].add(fib[i-3].add(fib[i-4])));
        }
    }
    
    public static void main(String[] args){
        in = new Scanner(new BufferedInputStream(System.in));
        
        initFib();
        while(in.hasNext()){
            int n = in.nextInt();
            System.out.println(fib[n]);
        }
    }
}