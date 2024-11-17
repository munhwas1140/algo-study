package week8.BOJ4386;

import java.util.*;
import java.io.*;

public class seho {
    static int[] parent;

    static int find(int x){
        if (parent[x] == x) return parent[x];

        parent[x] = find(parent[x]);
        return parent[x];
    }

    static void union(int a, int b){
        a = find(a);
        b = find(b);

        if(a < b) parent[b] = a;
        else parent[a] = b;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int n = Integer.parseInt(br.readLine());

        float[][] stars = new float[n][2];

        PriorityQueue<float[]> q = new PriorityQueue<>(new Comparator<float[]>() {
            @Override
            public int compare(float[] a, float[] b) {
                return Float.compare(a[0], b[0]);
            }
        });
        parent = new int[n];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            stars[i][0] = Float.parseFloat(st.nextToken());
            stars[i][1] = Float.parseFloat(st.nextToken());
            parent[i] = i;
        }

        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                float dist = (float) Math.sqrt(Math.pow(stars[i][0] - stars[j][0], 2)
                        + Math.pow(stars[i][1] - stars[j][1], 2));
                q.add(new float[] {dist, (float) i, (float) j});
            }
        }
        float ans = 0f;

        while (!q.isEmpty()) {

            float dist = q.peek()[0];
            int a = (int) q.peek()[1];
            int b = (int) q.poll()[2];

            if (find(a) != find(b)) {
                ans += dist;
                union(a, b);
            }
        }

        System.out.printf("%.2f", ans);
    }
}
