package week3.BOJ1260;

import java.util.*;
import java.io.*;

public class seho {
    public static void dfs(int node, ArrayList<ArrayList<Integer>> graph, boolean[] visited) {
        if (visited[node]) return;

        visited[node] = true;
        System.out.print(node + " ");

        for (int next : graph.get(node)) {
            dfs(next, graph, visited);
        }
    }

    public static void bfs(ArrayList<ArrayList<Integer>> graph, boolean[] visited, ArrayList<Integer> queue) {
        while (!queue.isEmpty()){
            int current = queue.remove(0);
            System.out.print(current + " ");

            for (int next : graph.get(current)) {
                if (!visited[next]) {
                    visited[next] = true;
                    queue.add(next);
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int v = Integer.parseInt(st.nextToken());

        ArrayList<ArrayList<Integer>> graph = new ArrayList<ArrayList<Integer>>(n+1);
        for (int i = 0; i <= n; i++) {
            graph.add(new ArrayList<Integer>());
        }
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            graph.get(a).add(b);
            graph.get(b).add(a);
            Collections.sort(graph.get(a));
            Collections.sort(graph.get(b));
        }
        boolean[] visited = new boolean[n+1];

        dfs(v, graph, visited);
        System.out.println();

        for (int i = 0; i < n+1; i++){
            visited[i] = false;
        }

        ArrayList<Integer> queue = new ArrayList<Integer>();
        queue.add(v);
        visited[v] = true;
        bfs(graph, visited, queue);
        System.out.println();
    }
}
