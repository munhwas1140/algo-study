package week2.BOJ1021;

import java.util.*;
import java.io.*;

public class seho {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        ArrayList<Integer> queue = new ArrayList<Integer>();

        for (int i = 1; i < n+1; i++) {
            queue.add(i);
        }

        st = new StringTokenizer(br.readLine());

        int cnt = 0;
        for(int i = 0; i < m; i++) {
            int num = Integer.parseInt(st.nextToken());

            if (num == queue.get(0)) {
                queue.remove(0);
            } else {
                if (queue.indexOf(num) > queue.size()/2) {
                    while (queue.get(0) != num){
                        queue.add(0, queue.remove(queue.size() - 1));
                        cnt++;
                    }
                    queue.remove(0);
                } else {
                    while(queue.get(0) != num) {
                        queue.add(queue.remove(0));
                        cnt++;
                    }
                    queue.remove(0);
                }
            }
        }
        System.out.println(cnt);
    }
}

// 1 2 3 4 5 6 7 8 9 10
// 2 3 4 5 6 7 8 9 10 1 v
// 3 4 5 6 7 8 9 10 1
// 1 3 4 5 6 7 8 9 10 v
// 10 1 3 4 5 6 7 8 9 v
// 9 10 1 3 4 5 6 7 8 v
// 10 1 3 4 5 6 7 8
