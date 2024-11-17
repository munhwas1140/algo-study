package week3.BOJ1182;

import java.util.*;
import java.io.*;

public class seho {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int s = Integer.parseInt(st.nextToken());

        int ans = 0;
        int[] nums = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++){
            nums[i] = Integer.parseInt(st.nextToken());
        }

        for (int i=1; i < (1<<n); i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                if ((i & (1<<j)) != 0) {
                    sum += nums[j];
                }
            }
            if (sum == s) {
                ans++;
            }
        }
        System.out.println(ans);
    }
}
