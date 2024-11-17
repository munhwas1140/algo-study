package week1.BOJ15787;

import java.io.*;
import java.util.*;

public class seho {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        Integer[] train = new Integer[n];

        Arrays.fill(train, 0);

        for(int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());

            int command = Integer.parseInt(st.nextToken());
            int no = Integer.parseInt(st.nextToken())-1;
            if(command == 1 || command == 2) {
                int seat = Integer.parseInt(st.nextToken())-1;

                if(command == 1) {
                    train[no] = train[no] | 1<<(seat);
                }
                if(command == 2) {
                    if ((train[no] & (1<<seat)) != 0) {
                        train[no] = train[no] ^ 1 << (seat);
                    }
                }
            } else if(command == 3) {
                if((train[no] & (1 << 19)) != 0) {
                    train[no] = train[no] & ~(1 << 19);
                }
                train[no] = train[no] << 1;
            } else if(command == 4) {
                if((train[no] & 1) != 0) {
                    train[no] -= 1;
                }
                train[no] = train[no] >> 1;
            }
        }

        Set<Integer> set = new HashSet<Integer>(Arrays.asList(train));
        System.out.println(set.size());
    }
}
