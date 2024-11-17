package week2.BOJ1918;

import java.util.*;
import java.io.*;

public class seho {
    public static int ISP(char c) {
        if (c == '(') {return 8;}
        else if (c == '*' || c == '/') {return 1;}
        else if (c == '+' || c == '-') {return 2;}
        return 9;
    }

    public static int ICP(char c) {
        if (c == '(') {return 0;}
        else if (c == '*' || c == '/') {return 1;}
        else if (c == '+' || c == '-') {return 2;}
        else if (c == '#') {return 8;}
        return 9;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        String infix = st.nextToken();

        ArrayList<Character> operation = new ArrayList<>();

        operation.add('#');
        for (char c : infix.toCharArray()) {
            if ((int)c < 91 && (int)c > 64) {
                System.out.print(c);
            } else {
                if (c == ')') {
                    while (!operation.isEmpty() && operation.get(operation.size() - 1)!= '(') {
                        System.out.print(operation.remove(operation.size() - 1));
                    }
                    operation.remove(operation.size() - 1);
                } else {
                    while (ICP(c) >= ISP(operation.get(operation.size() - 1))){
                        System.out.print(operation.remove(operation.size() - 1));
                    }
                    operation.add(c);
                }
            }
        }
        while (!operation.isEmpty()) {
            if (operation.get(operation.size()-1) == '#'){break;}
            System.out.print(operation.remove(operation.size() - 1));
        }
    }
}
