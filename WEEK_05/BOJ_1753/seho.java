package week5.BOJ1753;

import java.util.*;
import java.io.*;

public class seho {
    static ArrayList<int[]>[] graph;
    static int[] dist;
    static int v, e, k;

    static void bfs(int node) {
        PriorityQueue<int[]> queue = new PriorityQueue<>(new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                if(o1[0] == o2[0]) {
                    return Integer.compare(o2[1], o1[1]);
                }
                return Integer.compare(o1[0], o2[0]);
            }
        });

        queue.add(new int[]{0, node});
        dist[node] = 0;

        while (!queue.isEmpty()) {
            int[] no = queue.poll();
            int now = no[1];
            int cost = no[0];

            for (int[] next : graph[now]) {
                int nextNode = next[0];
                int nextCost = cost + next[1];

                if (nextCost < dist[nextNode]) {
                    dist[nextNode] = nextCost;
                    queue.add(new int[]{nextCost, nextNode});
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        v = Integer.parseInt(st.nextToken());
        e = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(br.readLine())-1;

        graph = new ArrayList[v];

        for (int i = 0; i < v; i++) {
            graph[i] = new ArrayList<>();
        }

        dist = new int[v];
        Arrays.fill(dist, 10000000);

        for (int i = 0; i < e; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken()) - 1;
            int b = Integer.parseInt(st.nextToken()) - 1;
            int c = Integer.parseInt(st.nextToken());
            graph[a].add(new int[]{b, c});
        }
        bfs(k);

        for (int i = 0; i < v; i++) {
            if (dist[i] == 10000000) {
                System.out.println("INF");
            } else {
                System.out.println(dist[i]);
            }
        }

//        Runtime.getRuntime().gc();
//        long usedMemory = Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory();
//        System.out.print(usedMemory + " bytes");
    }
}

// 1473792
// 1473688