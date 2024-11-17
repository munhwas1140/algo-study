package week8.BOJ2644;

import java.util.*;
import java.io.*;

public class seho {
    static ArrayList[] familyTree; // 가계도
    static boolean[] visited;
    static int cnt;

    static int bfs(int x, int y){
        Queue<Integer> queue = new LinkedList<>();

        queue.add(x);
        visited[x] = true;
        while (!queue.isEmpty()){
            int l = queue.size();

            for (int t = 0; t < l; t++) {
                int node = queue.poll();
                for (Object nextNode : familyTree[node]) {
                    if (visited[(int)nextNode]) continue;
                    queue.add((int)nextNode);
                    visited[(int) nextNode] = true;
                    if ((int)nextNode == y) {
                        return ++cnt;
                    }
                }
            }
            cnt++;
        }
        if(!visited[y]) {return -1;}
        return cnt;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(br.readLine());

        // static 변수 초기화
        visited = new boolean[n + 1];
        familyTree = new ArrayList[n + 1];
        for (int i=0; i < n+1; i++) {
            familyTree[i] = new ArrayList();
        }


        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());

            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());

            familyTree[x].add(y);
            familyTree[y].add(x);
        }

        System.out.println(bfs(a, b));

    }
}
