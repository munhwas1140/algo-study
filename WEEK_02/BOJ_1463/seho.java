package week2.BOJ1463;

import java.util.*;
import java.io.*;

public class seho {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] dp = new int[n+1];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = 0;
        dp[1] = 0;

        // 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
        // 0, 0, 1, 1, 2, 3, 2, 3, 3, 2, 3,

        for(int i = 2; i <= n ; i++) {
            if (i%2 == 0) {
                dp[i] = Math.min(dp[i], dp[i/2] + 1);
            }
            if(i%3 == 0) {
                dp[i] = Math.min(dp[i], dp[i/3] + 1);
            }
            dp[i] = Math.min(dp[i], dp[i-1] + 1);
        }

        // System.out.println(Arrays.toString(dp));
        System.out.println(dp[n]);
    }
}
