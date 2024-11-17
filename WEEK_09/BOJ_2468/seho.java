package week9.BOJ2468;

import java.util.*;
import java.io.*;

public class seho {
    static int n;
    static int[][] area;
    static boolean[][] visited;

    static int[] dx = {1, 0, -1, 0};
    static int[] dy = {0, 1, 0, -1};

    static void bfs(int i, int j){
        Queue<int[]> q = new LinkedList<>();

        q.add(new int[]{i, j});
        visited[i][j] = true;
        while(!q.isEmpty()){
            int[] cur = q.poll();
            int x = cur[0];
            int y = cur[1];
            for(int k = 0; k < 4; k++){
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx < 0 || ny < 0 || nx >= n || ny >= n || visited[nx][ny] || area[nx][ny] == 0) continue;
                visited[nx][ny] = true;
                q.add(new int[]{nx, ny});
            }
        }
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        n = Integer.parseInt(br.readLine());
        area = new int[n][n];
        ArrayList<Integer> height = new ArrayList<>();
        int max = 1;

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                area[i][j] = Integer.parseInt(st.nextToken());
                if(!height.contains(area[i][j])) {
                    height.add(area[i][j]);
                }
            }
        }
        Collections.sort(height);

        for (int h : height) {
            visited = new boolean[n][n];
            int ans = 0;

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if(area[i][j] <= h) {
                        area[i][j] = 0;
                    }
                }
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (area[i][j] != 0 && !visited[i][j]) {
                        bfs(i, j);
                        ans++;
                    }
                }
            }
            max = Math.max(max, ans);
        }

        System.out.println(max);
    }
}
