package week2.BOJ1449;

import java.util.*;
import java.io.*;

public class seho {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int l = Integer.parseInt(st.nextToken());
        int[] pipe = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            pipe[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(pipe);
        int ans = 1;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (pipe[j] - pipe[i] + 1 > l) {
                    ans++;
                    i = j;
                }
            }
        }
        System.out.println(ans);
    }
}
