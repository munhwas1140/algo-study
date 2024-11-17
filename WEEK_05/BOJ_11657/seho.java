package week5.BOJ11657;

import java.util.*;
import java.io.*;

public class seho {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        int v = Integer.parseInt(st.nextToken());
        int e = Integer.parseInt(st.nextToken());

        ArrayList<int[]>[] graph = new ArrayList[v];

        for (int i = 0; i < v; i++) {
            graph[i] = new ArrayList<>();
        }

        long[] dist = new long[v];
        Arrays.fill(dist, Integer.MAX_VALUE);

        for (int i = 0; i < e; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken()) - 1;
            int b = Integer.parseInt(st.nextToken()) - 1;
            int c = Integer.parseInt(st.nextToken());
            graph[a].add(new int[]{b, c});
        }

        dist[0] = 0;

        loop:
        for (int t = 0; t < v+1; t++) {
            for (int i = 0; i < v; i++) {
                for (int[] info : graph[i]) {
                    int nextNode = info[0];
                    int nextCost = info[1];

                    if(dist[i] == Integer.MAX_VALUE) continue;

                    if(dist[nextNode] > nextCost + dist[i]) {
                        if(t==v) {dist[0] = -1; break loop;}
                        dist[nextNode] = nextCost + dist[i];
                    }
                }
            }
        }


        if (dist[0] == -1) {
            System.out.println(-1);
        }else {
            for (int i = 1; i < v; i++) {
                if (dist[i] == Integer.MAX_VALUE) {
                    System.out.println(-1);
                } else {
                    System.out.println(dist[i]);
                }
            }
        }
    }
}
