package week7.BOJ1516;

import java.util.*;
import java.io.*;

public class seho {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());
        int[] time = new int[n];
        int[] ans = new int[n];
        ArrayList[] graph = new ArrayList[n];
        int[] outdegree = new int[n];

        for(int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
        }

        for(int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());

            time[i] = Integer.parseInt(st.nextToken());
            ans[i] = time[i];

            while (true) {
                int a = Integer.parseInt(st.nextToken());
                if(a == -1) break;
                graph[a - 1].add(i);
                outdegree[i]++;
            }
        }

        // 우선순위 큐 선언 및 out degree가 0이면 queue에 삽입
        PriorityQueue<Integer> queue = new PriorityQueue<>();
        for (int i = 0; i < n; i++) {
            if (outdegree[i] == 0) {
                queue.add(i);
            }
        }

        while (!queue.isEmpty()) {
            int node = queue.poll();
            for (Object next : graph[node]) {
                int nextNode = (int) next;
                ans[nextNode] = Math.max(ans[nextNode], ans[node] + time[nextNode]); // 시간이 다 지나야 건물을 지을 수 있기 때문에 max를 이용하
                outdegree[nextNode]--;
                if (outdegree[nextNode] == 0) {
                    queue.add(nextNode);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            System.out.println(ans[i]);
        }
    }
}
