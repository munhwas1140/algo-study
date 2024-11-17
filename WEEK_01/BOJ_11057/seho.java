package week1.BOJ11057;

import java.util.*;
import java.io.*;

public class seho {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());

        int[][] arr = new int[n][10];
        for (int i=0; i<10; i++) {
            arr[0][i] = i+1;
        }

        for(int i=1; i<n; i++) {
            for(int j=0; j<10; j++) {
                for(int k=0; k<j+1; k++) {
                    arr[i][j] += arr[i-1][k] % 10007;
                }

            }
        }

        System.out.println(arr[n - 1][9] % 10007);
    }
}

// 1 2 3 4 5 6 7 8 9 10
// sum(10) sum(9)

// 10 55 220 715 2002
// 45 165 495 1287

// 0 1 2 3 4 5 6 7 8 9

// 00 01 02 03 04 05 06 07 08 09
// 11 12 13 14 15 16 17 18 19
// 22 23 24 25 26 27 28 29
// 33 34 35 36 37 38 39
// ...
// 99
// sum(10)

// n = 3
// 000 001 002 ... 009
// 011 012 ... 019
// ...
// 099
// 111 112 ... 119
//
// sum(10) + sum(9) + ... sum(1)

//n=4
// 0000 0001 0002 ... 0009
// ...
// 0009

// sum(10) + sum(9) + ... sum(1)
// + sum(9) + sum(8) + ...

// 1 2 3 4 5 6 7 8 9 10
// sum(10) sum(9)