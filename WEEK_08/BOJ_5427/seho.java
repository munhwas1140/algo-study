package week8.BOJ5427;

import java.util.*;
import java.io.*;

public class seho {
    static int n;
    static int m;
    static int ans;
    static int[] dx = {0, 1, 0, -1};
    static int[] dy = {1, 0, -1, 0};
    static char[][] building;
    static Queue<int[]> queueMove;
    static Queue<int[]> queueFire;
    static boolean[][] visited;

    static boolean move(){
        int l = queueMove.size();

        for(int t = 0; t < l; t++){
            int y = queueMove.peek()[0];
            int x = queueMove.poll()[1];

            if (x == 0 || y == 0 || x == m - 1 || y == n - 1) return true;

            for(int i=0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx < 0 || ny < 0 || nx >= m || ny >= n || building[ny][nx] == '*' || building[ny][nx] == '#' || visited[ny][nx])  continue;
                visited[ny][nx] = true;
                queueMove.add(new int[]{ny, nx});

                if(nx == 0 || ny == 0 || nx == m - 1 || ny == n - 1){
                    ans++;
                    return true;
                }
            }
        }
        ans++;
        return false;
    }

    static void fire(){

        int l = queueFire.size();
        for(int t = 0; t < l; t++){
            int y = queueFire.peek()[0];
            int x = queueFire.poll()[1];

            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if(ny < 0 || nx < 0 || ny >= n || nx >= m || building[ny][nx] != '.') continue;
                building[ny][nx] = '*';
                queueFire.add(new int[]{ny, nx});
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int T = Integer.parseInt(br.readLine());

        for (int t = 0; t < T; t++) {
            st = new StringTokenizer(br.readLine());
            m = Integer.parseInt(st.nextToken());
            n = Integer.parseInt(st.nextToken());
            ans = 0;

            building = new char[n][m];

            for (int i = 0; i < n; i++) {
                String s = br.readLine();

                for (int j = 0; j < m; j++) {
                    building[i][j] = s.charAt(j);
                }
            }

            visited = new boolean[n][m];
            queueMove = new LinkedList<>();
            queueFire = new LinkedList<>();

            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    visited[i][j] = false;
                    if (building[i][j] == '@') {
                        queueMove.add(new int[]{i, j});
                        visited[i][j] = true;
                    }
                    if (building[i][j] == '*') {
                        queueFire.add(new int[]{i, j});
                    }
                }
            }

            while (true) {
                fire();
                if (move()) {
                    System.out.println(++ans);
                    break;
                }
                if(ans > n*m) {
                    System.out.println("IMPOSSIBLE");
                    break;
                }
            }


        }
    }
}
