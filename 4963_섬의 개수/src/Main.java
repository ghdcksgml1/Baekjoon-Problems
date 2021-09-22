// 언어 : JAVA , (성공/실패) : 1/0 , 메모리 : 18112 KB , 시간 : 184 ms

import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static int X;
    static int Y;
    // DFS
    private static boolean dfs(int[][] graph,int x,int y){
        if(x < 0 || y < 0 || x >= X || y >= Y){
            return false;
        }
        // 인접해있는 섬을 알기 위해서
        // 상하좌우, 대각선까지 탐색
        if(graph[x][y] == 1){
            graph[x][y] = 0;
            dfs(graph,x,y+1);
            dfs(graph,x,y-1);
            dfs(graph,x+1,y);
            dfs(graph,x-1,y);
            dfs(graph,x+1,y+1);
            dfs(graph,x+1,y-1);
            dfs(graph,x-1,y+1);
            dfs(graph,x-1,y-1);
            return true;
        }
        return false;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        while(true) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            Y = Integer.parseInt(st.nextToken());
            X = Integer.parseInt(st.nextToken());
            if(X == 0 && Y == 0) break; // X, Y가 0이면, while문 종료
            int[][] graph = new int[X][Y];

            // 각 줄을 받아서 graph 배열에 입력시킨다.
            for(int i=0;i<X;i++){
                st = new StringTokenizer(br.readLine()," ");
                for(int j=0;j<Y;j++){
                    graph[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            int result = 0;
            for(int i=0;i<X;i++) {
                for (int j = 0; j < Y; j++) {
                    // 섬을 찾은 경우 result를 1씩 증가시킨다.
                    if (dfs(graph,i, j)) {
                        result++;
                    }
                }
            }
            System.out.println(result);
        }
    }
}
