// 언어 : JAVA , (성공/실패) : 1/4 , 메모리 : 212096 KB , 시간 : 892 ms
import java.util.*;
import java.io.*;

public class Main {
    public static ArrayList<Long> tree;

    public static void build(long[]arr, int size){
        tree = new ArrayList<>();
        long[] temp = new long[size*4];
        for(long i:temp){
            tree.add(i);
        }
        buildRec(arr,1,0,size-1);
    }

    public static long buildRec(long[] arr,int node, int nodeLeft,int nodeRight){
        if(nodeLeft == nodeRight){
            tree.set(node,arr[nodeLeft]);
            return tree.get(node);
        }
        int mid = nodeLeft + (nodeRight - nodeLeft)/2;
        long leftVal = buildRec(arr,node*2,nodeLeft,mid);
        long rightVal = buildRec(arr,node*2+1,mid+1,nodeRight);

        tree.set(node,leftVal+rightVal);
        return tree.get(node);
    }

    public static long querySec(int left,int right,int node,int nodeLeft,int nodeRight){
        if(right<nodeLeft || left > nodeRight)
            return 0; // default value
        if(left<=nodeLeft && right >= nodeRight)
            return tree.get(node);

        int mid = nodeLeft + (nodeRight - nodeLeft)/2;
        return querySec(left,right,node*2,nodeLeft,mid)
                + querySec(left,right,node*2+1,mid+1,nodeRight);
    }

    public static long query(int left,int right,int size){
        return querySec(left,right,1,0,size-1);
    }

    public static long updateRec(int index,long newValue,int node,int nodeLeft,int nodeRight){
        if(index < nodeLeft || index > nodeRight)
            return tree.get(node);
        if(nodeLeft == nodeRight) {
            tree.set(node, newValue);
            return tree.get(node);
        }

        int mid = nodeLeft + (nodeRight - nodeLeft)/2;
        long leftVal = updateRec(index,newValue,node*2,nodeLeft,mid);
        long rightVal = updateRec(index, newValue, node*2+1, mid+1, nodeRight);

        tree.set(node, leftVal+rightVal);
        return tree.get(node);
    }

    public static long update(int index,long newValue,int size){
        return updateRec(index,newValue,1,0,size-1);
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine()," ");

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        long[] arr = new long[N];

        for(int i=0;i<N;i++){
            arr[i] = Integer.parseInt(br.readLine());
        }

        build(arr,N);
        for(int i=0;i<M+K;i++){
            st = new StringTokenizer(br.readLine()," ");
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            long c = Long.parseLong(st.nextToken());
            if(a == 1){
                update(b-1,c,N);
            }else{
                System.out.println(query(b-1, (int)c-1,N));
            }
        }
    }
}
