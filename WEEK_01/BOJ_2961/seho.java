package week1.BOJ2961;

import java.io.*;
import java.util.*;

public class seho {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine());
        int[][] taste = new int[t][2];
        int ans = Integer.MAX_VALUE;

        for (int i = 0; i < t; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            taste[i][0] = Integer.parseInt(st.nextToken());
            taste[i][1] = Integer.parseInt(st.nextToken());
        }

        for (int i = 1; i < (1<<t); i++){
            int sums = 0;
            int mulb = 1;
            for (int j=0; j < t; j++) {
                if ((i & 1 << j) != 0) {
                    sums += taste[j][1];
                    mulb *= taste[j][0];
                }
            }
            ans = Math.min(Math.abs(sums - mulb), ans);
        }

        System.out.println(ans);
    }
}
