package week7.BOJ1700;

import java.util.*;
import java.io.*;

public class seho {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int ans = 0;

        ArrayList<Integer> power = new ArrayList<>();
        int[] schedule = new int[m];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < m; i++) {
            schedule[i] = Integer.parseInt(st.nextToken());
        }
        if (n==1) {
            for(int i=0; i<m-1; i++) {
                if (schedule[i] != schedule[i + 1]) {
                    ans++;
                }
            }
        }
        else {
            int idx = 0;
            while (power.size() < n && idx < m) {
                int machine = schedule[idx];
                if (!power.contains(machine)) {
                    power.add(machine);
                }
                idx++;
            }

            List<Boolean> visited = new ArrayList<>();
            for (int j = 0; j < n; j++) {visited.add(false);}
            for (int i = idx; i < m; i++) {
                if (power.contains(schedule[i])) {continue;}
                for (int j = 0; j < n; j++) {visited.set(j, false);}

                for (int j = i + 1; j < m; j++) {
                    int loc = power.indexOf(schedule[j]);
                    if (loc == -1) {continue;}
                    visited.set(loc, true);

                    if (Collections.frequency(visited, false) == 1) {break;}
                }
                power.set(visited.indexOf(false), schedule[i]);
                ans++;
            }
        }

        System.out.println(ans);
    }
}

// 2 3
// 1 3 // 2 1



// 1 2 3 4 5 1 2 1 2 3
// 1 2 3
// 4 2 3 , 1 4 3 , 1 2 4
