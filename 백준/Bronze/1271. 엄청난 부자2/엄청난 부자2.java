// 언어 : JAVA , (성공/실패) : 1/4 , 메모리 : 45008 KB , 시간 : 208 ms
import java.math.BigInteger;
import java.util.*;
import java.io.*;

public class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine()," ");
        BigInteger n = new BigInteger(st.nextToken());
        BigInteger m = new BigInteger(st.nextToken());
        BigInteger[] result = n.divideAndRemainder(m);
        System.out.println(result[0]);
        System.out.println(result[1]);

        bw.flush();
        bw.close();
        br.close();
    }
}