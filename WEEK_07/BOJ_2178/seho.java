package week7.BOJ2178;

import java.util.*;
import java.io.*;

public class seho {
    static int[][] maze;
    static boolean[][] visited;
    static int[] dx = {0, 1, 0, -1};
    static int[] dy = {1, 0, -1, 0};
    static int m;
    static int n;
    static int cnt = 0;

    public static void bfs() {
        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[]{0, 0});

        while (!queue.isEmpty()) {
            int l = queue.size();

            for (int t = 0; t < l; t++) {
                int x = queue.peek()[0];
                int y = queue.poll()[1];
                visited[y][x] = true;

                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if(nx<0 || ny<0 || nx>=m || ny>=n || visited[ny][nx] || maze[y][x] == 0) continue;

                    queue.add(new int[]{nx, ny});
                    visited[ny][nx] = true;
                }
                if (x == m - 1 && y == n - 1) {
                    cnt++;
                    return;
                }
            }
            cnt++;
        }

    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        maze = new int[n][m];
        visited = new boolean[n][m];

        for (int i = 0; i < n; i++) {
            String str = br.readLine();
            for (int j = 0; j < m; j++) {
                maze[i][j] = Integer.parseInt(String.valueOf(str.charAt(j)));
            }
            Arrays.fill(visited[i], false);
        }
        bfs();
        System.out.println(cnt);

    }
}
