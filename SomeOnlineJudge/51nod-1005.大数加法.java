import java.util.Scanner;
import java.io.BufferedInputStream;
import java.math.BigInteger;
public class Main{
    private static Scanner in;
    public static void main(String[] args){
        in = new Scanner(new BufferedInputStream(System.in));
        BigInteger a = in.nextBigInteger();
        BigInteger b = in.nextBigInteger();
        System.out.println(a.add(b));
    }
}