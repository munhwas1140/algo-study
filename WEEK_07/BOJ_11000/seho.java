package week7.BOJ11000;

import java.util.*;
import java.io.*;

public class seho {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int n = Integer.parseInt(br.readLine());

        ArrayList<int[]> room = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int t = Integer.parseInt(st.nextToken());
            room.add(new int[]{s, t});
        }

        room.sort((a, b) -> a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]);
        PriorityQueue<Integer> time = new PriorityQueue<>();
        time.add(room.get(0)[1]);
        for (int i = 1; i < n; i++) {
            if (time.peek() <= room.get(i)[0]) {
                time.poll();
                time.add(room.get(i)[1]);
            } else {
                time.add(room.get(i)[1]);
            }
        }

        System.out.println(time.size());
    }
}
