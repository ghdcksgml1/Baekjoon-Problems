// 언어 : JAVA , (성공/실패) : 2/1 , 메모리 : 209132 KB , 시간 : 772 ms
import java.util.*;
import java.io.*;

public class Main {
    public static ArrayList<Long> tree;

    public static long merge(long left,long right){
        return (left * right) % 1000000007;
    }

    public static long buildRec(long[] arr,int node,int nodeLeft,int nodeRight){
        if(nodeLeft == nodeRight){
            tree.set(node,arr[nodeLeft]);
            return tree.get(node);
        }

        int mid = nodeLeft + (nodeRight - nodeLeft)/2;
        Long leftVal = buildRec(arr,node*2,nodeLeft,mid);
        Long rightVal = buildRec(arr,node*2+1,mid+1,nodeRight);

        tree.set(node,merge(leftVal,rightVal));
        return tree.get(node);
    }

    public static void build(long[] arr,int size){
        tree = new ArrayList<>();
        for(int i=0;i<size*4;i++){
            tree.add((long)0);
        }
        buildRec(arr,1,0,size-1);
    }

    public static long qureyRec(int left,int right,int node, int nodeLeft,int nodeRight){
        if(right<nodeLeft || left > nodeRight){
            return 1;
        }
        if(left<=nodeLeft && nodeRight <= right)
            return tree.get(node);

        int mid = nodeLeft + (nodeRight - nodeLeft)/2;
        return merge(qureyRec(left,right,node*2,nodeLeft,mid)
                ,qureyRec(left,right,node*2+1,mid+1,nodeRight));
    }

    public static long query(int left,int right,int size){
        return qureyRec(left,right,1,0,size-1);
    }

    public static long updateRec(int index,long newValue,int node, int nodeLeft,int nodeRight){
        if(index<nodeLeft || nodeRight < index)
            return tree.get(node);
        if(nodeLeft == nodeRight){
            tree.set(node,newValue);
            return tree.get(node);
        }

        int mid = nodeLeft + (nodeRight - nodeLeft)/2;
        long leftVal = updateRec(index,newValue,node*2,nodeLeft,mid);
        long rightVal = updateRec(index,newValue,node*2+1,mid+1,nodeRight);

        tree.set(node,merge(leftVal,rightVal));
        return tree.get(node);
    }

    public static void update(int index,long newValue,int size){
        updateRec(index,newValue,1,0,size-1);
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine()," ");

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        long[] arr = new long[N];

        for(int i=0;i<N;i++){
            arr[i] = Long.parseLong(br.readLine());
        }

        build(arr,N);
        for(int i=0;i<M+K;i++){
            st = new StringTokenizer(br.readLine()," ");
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            long c = Long.parseLong(st.nextToken());

            if(a==1){
                update(b-1,c,N);
            }else{
                Long reuslt = query(b-1,(int)(c-1),N);
                bw.write(reuslt+"\n");
            }
        }
        bw.flush();
        bw.close();
        br.close();
    }
}
