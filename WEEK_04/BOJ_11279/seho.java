package week4.BOJ11279;

import java.util.*;
import java.io.*;

public class seho {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        PriorityQueue<Integer> nums = new PriorityQueue<>(Collections.reverseOrder());

        for (int i = 0; i < n; i++) {
            int x = Integer.parseInt(br.readLine());

            if (x == 0) {
                if (!nums.isEmpty()) {
                    System.out.println(nums.poll());
                } else {
                    System.out.println(0);
                }
            }
            else {
                nums.add(x);
            }
        }

    }
}
