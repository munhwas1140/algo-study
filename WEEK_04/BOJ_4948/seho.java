package week4.BOJ4948;

import java.util.*;
import java.io.*;

public class seho {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        boolean[] isPrime = new boolean[2*123456 + 1];
        Arrays.fill(isPrime, true);

        for (int i = 2; i * i <= 2 * 123456; i++) {
            if (!isPrime[i]) {continue;}

            for (int j = i+i; j <= 2 * 123456; j += i) {
                isPrime[j] = false;
            }
        }

        while (true) {
            int n = Integer.parseInt(br.readLine());

            if (n == 0) break;

            int count = 0;

            for (int i = n+1; i <= 2*n; i++) {
                if (isPrime[i]) {
                    count++;
                }
            }
            System.out.println(count);
        }

    }
}
