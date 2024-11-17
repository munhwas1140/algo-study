package week3.BOJ11724;

import java.util.*;
import java.io.*;

public class seho {

    public static int[] graph;

    public static int find(int node){
        if (node == graph[node]) {return node;}
        else {
            int x = find(graph[node]);
            graph[node] = x;
            return x;
        }
    }

    public static void union(int a, int b){
        a = find(a);
        b = find(b);
        if (a < b) {graph[b] = a;}
        else if (a > b) {graph[a] = b;}
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        graph = new int[n+1];
        for (int i = 0; i < n+1; i++) {
            graph[i] = i;
        }
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            union(a, b);
        }
        Set<Integer> answer = new HashSet<Integer>();
        for (int i = 1; i < n+1; i++){
            answer.add(find(graph[i]));
        }
        System.out.println(answer.size());
    }
}
