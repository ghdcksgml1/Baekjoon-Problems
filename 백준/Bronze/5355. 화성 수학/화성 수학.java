// 언어 : JAVA , (성공/실패) : 1/4 , 메모리 : 45008 KB , 시간 : 208 ms
import java.util.*;
import java.io.*;

public class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());
        for(int i=0; i<T; i++){
            StringTokenizer str = new StringTokenizer(br.readLine(), " ");
            double N = Double.parseDouble(str.nextToken());
            while(str.hasMoreTokens()){
                String s = str.nextToken();
                if(s.equals("@")){
                    N *= 3.0;
                }else if(s.equals("%")){
                    N += 5.0;
                }else{
                    N -= 7.0;
                }
            }
            System.out.printf("%.2f\n",N);
        }

        bw.flush();
        bw.close();
        br.close();
    }
}