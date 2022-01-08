// 언어 : JAVA , (성공/실패) : 1/7 , 메모리 : 40208 KB , 시간 : 380 ms
import java.util.*;
import java.io.*;

public class Main{
    public static ArrayList<Integer> tree = new ArrayList<>();

    public static void build(int size){
        for(int i=0;i<size*4;i++){
            tree.add(0);
        }
        buildRec(1,0,size-1);
    }

    public static int buildRec(int node, int nodeLeft, int nodeRight){
        if(nodeLeft == nodeRight){
            tree.set(node, 1);
            return 1;
        }
        int mid = nodeLeft + (nodeRight - nodeLeft) / 2;
        int leftVal = buildRec(node * 2, nodeLeft, mid);
        int rightVal = buildRec(node * 2 + 1, mid + 1, nodeRight);
        tree.set(node, leftVal + rightVal);
        return tree.get(node);
    }

    // 트리를 한 구간씩 내려가면서 rank의 위치를 찾음
    // ex.) 처음 시도에 rank = 6 이면
    // tree[node * 2] = 4, tree[node * 2 + 1] = 3 이므로
    // 오른쪽으로 이동하고 6 - 4 = 2 으로 rank를 갱신
    // 그 다음 구간에서는 tree[node * 2] = 2, tree[node * 2 + 1] = 1 이므로
    // 왼쪽으로 이동하고, rank는 그대로
    // 그 다음 구간에서는 tree[node * 2] = 1, tree[node * 2 + 1] = 1 이므로
    // rank는 2 - 1 = 1 이 되고, nodeLeft == nodeRight가 되면서
    // nodeLeft + 1의 결과값인 6이 반환된다.
    // 모든 구간을 내려갈때마다 tree에 -1을 해주기때문에, 6과 연관된 노드들의 값이 갱신된다.

    public static int query(int rank, int node, int nodeLeft, int nodeRight){
        tree.set(node,tree.get(node)-1);
        if(nodeLeft == nodeRight){
            return nodeLeft + 1;
        }
        int mid = nodeLeft + (nodeRight - nodeLeft) / 2;
        if(tree.get(node * 2) >= rank) return query(rank, node * 2, nodeLeft, mid);
        else return query(rank - tree.get(node * 2), node * 2 + 1, mid + 1, nodeRight);
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine()," ");
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        build(N);

        StringBuilder sb = new StringBuilder();

        int idx = K;
        sb.append("<");

        for(int i=0;i<N-1;i++){
            sb.append((query(idx,1,0,N-1)));
            if(i<N-1){
                idx = (idx + K - 2) % (N - i - 1) + 1;
                sb.append(", ");
            }
        }
        sb.append((query(idx,1,0,N-1)));
        sb.append(">");
        bw.write(sb.toString());
        bw.flush();
        bw.close();
        br.close();
    }
}