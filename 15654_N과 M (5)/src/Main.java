// 언어 : JAVA , (성공/실패) : 1/0 , 메모리 : 75728 KB , 시간 : 2600 ms
import java.util.*;
import java.io.*;

public class Main {
    public static int N,M;
    public static int[] arr;
    public static boolean[] check;
    public static ArrayList<Integer> vector = new ArrayList<>();

    public static void backtracking(int x){
        if(x == M){
            for(int a:vector){
                System.out.print(a+" ");
            }
            System.out.println();
            return;
        }
        for(int i=0;i<N;i++){
            if(!check[i]){
                check[i] = true;
                vector.add(arr[i]);
                backtracking(x+1);
                vector.remove(x);
                check[i] = false;
            }
        }
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine()," ");

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        arr = new int[N];
        check = new boolean[N];

        st = new StringTokenizer(br.readLine()," ");
        for(int i=0;i<N;i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(arr);

        backtracking(0);
    }
}
