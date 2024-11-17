package week4.BOJ9252;

import java.util.*;
import java.io.*;

public class seho {
    static String a, b;
    static int[][] dp;
    static String s = "";
    static void lcs(int i, int j){
        if(i == 0 || j == 0) {
            return;
        }

        if(a.charAt(i-1) == b.charAt(j-1)) {
            lcs(i-1, j-1);
            s += a.charAt(i-1);
        } else if(dp[i][j-1] > dp[i-1][j]) {
            lcs(i, j-1);
        } else {
            lcs(i-1, j);
        }
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        a = br.readLine();
        b = br.readLine();

        dp = new int[a.length()+1][b.length()+1];

        for (int i = 0; i < a.length(); i++) {
            for (int j = 0; j < b.length(); j++) {
                if (a.charAt(i) == b.charAt(j)) {
                    dp[i+1][j+1] = dp[i][j] + 1;
                } else {
                    dp[i+1][j+1] = Math.max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        lcs(a.length(), b.length());
        System.out.println(s.length());
        System.out.println(s);
    }
}