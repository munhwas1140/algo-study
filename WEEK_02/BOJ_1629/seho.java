package week2.BOJ1629;

import java.util.*;
import java.io.*;

public class seho {
    public static long pow(long a, long b, long c) {
        if (b == 0) return 1;
        if (b % 2 == 1) return pow(a, b - 1, c) * a % c;
        long num = pow(a, b/2, c);
        return num * num % c;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        long a = Long.parseLong(st.nextToken());
        long b = Long.parseLong(st.nextToken());
        long c = Long.parseLong(st.nextToken());

        System.out.println(pow(a, b, c));
    }
}