package week3.BOJ11659;

import java.util.*;
import java.io.*;

public class seho {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        int[] arr = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            if (i == 0) arr[i] = Integer.parseInt(st.nextToken());
            else arr[i] = arr[i-1] + Integer.parseInt(st.nextToken());
        }

        for (int j = 0; j < m; j++) {
            st = new StringTokenizer(br.readLine());

            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            if (a == 1) {
                System.out.println(arr[b-1]);
            } else
                System.out.println(arr[b-1] - arr[a-2]);
        }
    }
}
// 5 4 3 2 1

// 5 9 12 14 15
//   4
//     3
//       2
//         1