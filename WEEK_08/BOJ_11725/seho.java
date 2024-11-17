package week8.BOJ11725;

import java.util.*;
import java.io.*;

public class seho {
    static ArrayList[] graph;
    static int[] parent;
    static boolean[] visited;

    static void dfs(int node) {
        if (visited[node]) {
            return;
        }
        visited[node] = true;
        for (int i = 0; i < graph[node].size(); i++) {
            int nextNode = (int) graph[node].get(i);
            if (visited[nextNode]) continue;
            parent[nextNode] = node;
            dfs(nextNode);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());

        graph = new ArrayList[n+1];
        visited = new boolean[n+1];
        parent = new int[n+1];

        for (int i = 0; i < n+1; i++) {
            graph[i] = new ArrayList();
            visited[i] = false;
            parent[i] = -1;
        }

        for (int i = 0; i < n-1; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            graph[a].add(b);
            graph[b].add(a);
        }

        dfs(1);

        for (int i = 2; i < parent.length; i++) {
            System.out.println(parent[i]);
        }
    }
}
