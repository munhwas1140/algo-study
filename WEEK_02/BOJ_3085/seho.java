package week2.BOJ3085;

import java.util.*;
import java.io.*;

public class seho {
    static int dx[] = {1, -1, 0, 0};
    static int dy[] = {0, 0, 1, -1};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());
        char[][] board = new char[n][n];

        for(int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            String s = st.nextToken();
            for(int j = 0; j < n; j++) {
                board[i][j] = s.charAt(j);
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            Set<Character> row = new HashSet<>();
            Set<Character> col = new HashSet<>();
            for(int j = 0; j < n; j++) {
                row.add(board[i][j]);
                col.add(board[j][i]);
            }
            if(row.size() == 1) {ans = 1; break;}
            if(col.size() == 1) {ans = 1; break;}
        }
        if(ans == 1) {
            System.out.println(n);
        }
        else {
            ans = 1;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    for (int d = 0; d < 4; d++) {
                        int nx = j + dx[d];
                        int ny = i + dy[d];
                        if (ny < 0 || ny >= n || nx < 0 || nx >= n) {continue;}

                        char tmp = board[i][j];
                        board[i][j] = board[ny][nx];
                        board[ny][nx] = tmp;
                        int col_num = 1;
                        int row_num = 1;
                        for(int k=0; k<n-1; k++) {
                            if(board[i][k] == board[i][k+1]){col_num++;}
                            else {ans = Math.max(ans, col_num); col_num = 1;}
                            if(board[k][j] == board[k+1][j]){row_num++;}
                            else {ans = Math.max(ans, row_num); row_num = 1;}
                        }
                        ans = Math.max(ans, col_num);
                        ans = Math.max(ans, row_num);
                        tmp = board[i][j];
                        board[i][j] = board[ny][nx];
                        board[ny][nx] = tmp;
                    }
                }
            }
            System.out.println(ans);
        }
    }
}
