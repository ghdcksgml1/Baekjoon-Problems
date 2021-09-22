// 언어 : JAVA , (성공/실패) : 1/1 , 메모리 : 14200 KB , 시간 : 140ms

import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String str = br.readLine();
        StringTokenizer st = new StringTokenizer(str," ");
        int A = Integer.parseInt(st.nextToken());
        int B = Integer.parseInt(st.nextToken());

        int result = A+B;
        bw.write(String.valueOf(result));
        br.close();
        bw.flush();
        bw.close();
    }
}
