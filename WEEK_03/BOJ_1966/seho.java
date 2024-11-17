package week3.BOJ1966;

import java.util.*;
import java.io.*;

public class seho {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        int T = Integer.parseInt(st.nextToken());

        for (int t = 0; t < T; t++) {
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());

            st = new StringTokenizer(br.readLine());
            ArrayList<Integer[]> nums = new ArrayList<>();

            for (int i = 0; i < n; i++) {
                nums.add(new Integer[]{i, Integer.parseInt(st.nextToken())});
            }

            int cnt = 0;
            while (true){
                for (int i = 1; i < nums.size(); i++) {
                    if (nums.get(i)[1] > nums.get(0)[1]) {
                        nums.add(nums.remove(0));
                        i = 0;
                    }
                }
                cnt++;
                if (nums.get(0)[0] == m){
                    break;
                }
                nums.remove(0);
            }
            System.out.println(cnt);
        }
    }
}
