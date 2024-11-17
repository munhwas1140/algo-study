package week4.BOJ1351;

import java.util.*;
import java.io.*;

public class seho {

    static HashMap<Long, Long> dp = new HashMap<>();

    static long dfs(long n, long p, long q) {
        if (dp.get(n) != null) {
            return dp.get(n);
        }

        dp.put(n, dfs(n / p, p, q) + dfs(n / q, p, q));
        return dp.get(n);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        long n = Long.parseLong(st.nextToken());
        long p = Long.parseLong(st.nextToken());
        long q = Long.parseLong(st.nextToken());

        dp.put((long) 0, (long) 1);

        System.out.println(dfs(n, p, q));

    }
}

// 0, 1/2 + 1/3, 2/2 + 2/3, 3/2 + 3/3, 4/2 + 4/3, 5/2 + 5/3
// 0, 0+0, 1+0, 1+1, 2+1, 2+1,