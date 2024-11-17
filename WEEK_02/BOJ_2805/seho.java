package week2.BOJ2805;

import java.util.*;
import java.io.*;

public class seho {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader((new InputStreamReader(System.in)));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        long[] trees = new long[n];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            trees[i] = Integer.parseInt(st.nextToken());
        }

        long max_h = Arrays.stream(trees).max().getAsLong();
        long min_h = 0;
        long h = 0;
        if(Arrays.stream(trees).sum() == m) {
            System.out.println(h);
            return;
        }
        while (true) {
            h = (max_h + min_h) / 2;
            long sum = 0;

            for (long tree : trees) {
                if (tree <= h) {continue;}
                sum += tree - h;
                if(sum > m) {break;}
            }

            if (sum > m) {min_h = h;}
            else if (sum < m) {max_h = h;}
            if (((max_h - min_h == 1) && (sum >= m)) || sum == m) {break;}
        }
        System.out.println(h);
    }
}
