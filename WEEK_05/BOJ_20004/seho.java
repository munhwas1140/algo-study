package week5.BOJ20004;

import java.io.*;

public class seho {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        for (int i = 1; i <= n; i++) {
            int num = 30;
            while (num > i) {
                num -= (i+1);
            }
            if (num <= 0) {
                System.out.println(i);
            }
        }
    }
}

// n = 2
// 31을 부르면 진다.
// 30을 부르면 이긴다.
// 27을 부르면 이긴다.
// 24
// 21
// 18
// 15
// 12
// 9
// 6
// 3

// n = 3
// 30
// 26
// 22
// 18
// 14
// 10
// 6
// 2


//1
//        2
//        4
//        5
//        9
//        14
//        29