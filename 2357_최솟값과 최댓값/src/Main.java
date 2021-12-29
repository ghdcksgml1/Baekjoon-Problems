// 언어 : JAVA , (성공/실패) : 1/0 , 메모리 : 81264 KB , 시간 : 1052 ms
import java.util.*;
import java.io.*;

public class Main {
    public static ArrayList<Integer> tree_min;
    public static ArrayList<Integer> tree_max;

    public static int merge_min(int left,int right){
        return Math.min(left,right);
    }

    public static int merge_max(int left,int right){
        return Math.max(left,right);
    }

    public static int BuildRec_min(int[] arr,int node,int nodeLeft,int nodeRight){
        if(nodeLeft == nodeRight){
            tree_min.set(node, arr[nodeLeft]);
            return tree_min.get(node);
        }

        int mid = nodeLeft + (nodeRight - nodeLeft)/2;
        int leftVal = BuildRec_min(arr,node*2,nodeLeft,mid);
        int rightVal = BuildRec_min(arr,node*2+1,mid+1,nodeRight);

        tree_min.set(node,merge_min(leftVal,rightVal));
        return tree_min.get(node);
    }

    public static void Build_min(int[] arr,int size){
        tree_min = new ArrayList<>();
        int[] temp = new int[size*4];
        for(int i : temp){
            tree_min.add(0);
        }
        BuildRec_min(arr,1,0,size-1);
    }

    public static int BuildRec_max(int[] arr,int node,int nodeLeft,int nodeRight){
        if(nodeLeft == nodeRight){
            tree_max.set(node, arr[nodeLeft]);
            return tree_max.get(node);
        }

        int mid = nodeLeft + (nodeRight - nodeLeft)/2;
        int leftVal = BuildRec_max(arr,node*2,nodeLeft,mid);
        int rightVal = BuildRec_max(arr,node*2+1,mid+1,nodeRight);

        tree_max.set(node,merge_max(leftVal,rightVal));
        return tree_max.get(node);
    }

    public static void Build_max(int[] arr,int size){
        tree_max = new ArrayList<>();
        int[] temp = new int[size*4];
        for(int i : temp){
            tree_max.add(0);
        }
        BuildRec_max(arr,1,0,size-1);
    }

    public static int queryRec_min(int left,int right,int node,int nodeLeft,int nodeRight){
        if(right < nodeLeft || left > nodeRight) // 범위 벗어날때
            return 1000000001;
        if(left<=nodeLeft && nodeRight<=right)
            return tree_min.get(node);

        int mid = nodeLeft + (nodeRight - nodeLeft)/2;
        int leftVal = queryRec_min(left,right,node*2,nodeLeft,mid);
        int rightVal = queryRec_min(left,right,node*2+1,mid+1,nodeRight);

        return merge_min(leftVal,rightVal);
    }

    public static int query_min(int left,int right,int size){
        return queryRec_min(left,right,1,0,size-1);
    }

    public static int queryRec_max(int left,int right,int node,int nodeLeft,int nodeRight){
        if(right < nodeLeft || left > nodeRight) // 범위 벗어날때
            return 0;
        if(left<=nodeLeft && nodeRight<=right)
            return tree_max.get(node);

        int mid = nodeLeft + (nodeRight - nodeLeft)/2;
        int leftVal = queryRec_max(left,right,node*2,nodeLeft,mid);
        int rightVal = queryRec_max(left,right,node*2+1,mid+1,nodeRight);

        return merge_max(leftVal,rightVal);
    }

    public static int query_max(int left,int right,int size){
        return queryRec_max(left,right,1,0,size-1);
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int[] arr_min = new int[N];
        int[] arr_max = new int[N];

        for(int i=0;i<N;i++){
            int temp = Integer.parseInt(br.readLine());
            arr_min[i] = temp;
            arr_max[i] = temp;
        }

        Build_min(arr_min,N);
        Build_max(arr_max,N);

        for(int i=0;i<M;i++){
            st = new StringTokenizer(br.readLine()," ");
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            bw.write(query_min(a-1,b-1,N)+" "+query_max(a-1,b-1,N)+"\n");
        }
        bw.flush();
        bw.close();
        br.close();
    }
}
