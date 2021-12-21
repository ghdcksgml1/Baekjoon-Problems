// 언어 : JAVA , (성공/실패) : 1/2 , 메모리 : 14492 KB , 시간 : 124 ms
import java.math.BigInteger;
import java.util.*;
import java.io.*;

public class Main {
    public static BigInteger[][] dp = new BigInteger[101][101];
    public static BigInteger dp(int N,int M){
        if(N == M || N == 0) return BigInteger.ONE;
        if(N == 1) return BigInteger.valueOf(M);
        if(dp[N][M] != BigInteger.ZERO){
            return dp[N][M];
        }
        BigInteger tmp1 = dp(N,M-1);
        BigInteger tmp2 = dp(N-1,M-1);
        dp[N][M] = tmp1.add(tmp2);
        return dp[N][M];
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine()," ");

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        for(int i=0;i<101;i++){
            for(int j=0;j<101;j++){
                dp[i][j] = BigInteger.ZERO;
            }
        }
        System.out.println(dp(m,n));
    }
}
