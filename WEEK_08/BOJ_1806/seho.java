package week8.BOJ1806;

import java.util.*;
import java.io.*;

public class seho {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int s = Integer.parseInt(st.nextToken());

        int nums[] = new int[n+1];
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i < n+1; i++) {
            nums[i] = Integer.parseInt(st.nextToken()) + nums[i-1];
        }

        int ans = 0;
        for (int i = 1; i < n+1; i++) {
            if(nums[i] >= s) {
                ans = i;
                break;
            }
        }
        if (nums[n] < s) {
            System.out.println(0);
        } else {
            for (int i = ans; i <= n; i++) {
                for (int j = i-ans; j < i; j++) {
                    if (nums[i] - nums[j] >= s) {
                        ans = Math.min(ans, i-j);
                    } else break;
                }
            }
            System.out.println(ans);
        }

    }
}
