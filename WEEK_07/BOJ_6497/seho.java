package week7.BOJ6497;

import java.util.*;
import java.io.*;

public class seho {
    static PriorityQueue<int[]> graph;
    public static int[] parent;
    public static int find(int x) {
        if (parent[x] == x) { return parent[x];}

        parent[x] = find(parent[x]);
        return parent[x];
    }

    public static void union(int x, int y){
        x = find(x);
        y = find(y);

        if(x < y){ parent[y] = x; }
        else if (x > y){ parent[x] = y;}
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        while (true){
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());

            if(n == 0 && m == 0) break;

            graph = new PriorityQueue<>(Comparator.comparingInt(o -> o[2]));
            parent = new int[n];
            int cost = 0;
            int all = 0;
            for(int i = 0; i < n; i++){
                parent[i] = i;
            }

            for(int i = 0; i < m; i++){
                st = new StringTokenizer(br.readLine());
                int x = Integer.parseInt(st.nextToken());
                int y = Integer.parseInt(st.nextToken());
                int z = Integer.parseInt(st.nextToken());

                graph.add(new int[]{x, y, z});
                all += z;
            }

            int[] check = new int[n];
            for (int i = 0; i < m; i++) {
                int[] edge = graph.poll();
                if (find(edge[0])!= find(edge[1])) {
                    union(edge[0], edge[1]);
                    cost += edge[2];
                }
                if (Arrays.equals(check, parent)) {
                    break;
                }
            }
            System.out.println(all - cost);

        }
    }
}
