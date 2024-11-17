package week7.BOJ5397;

import java.util.*;
import java.io.*;

public class seho {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        for (int t = 0; t < T; t++) {
            String key = br.readLine();

            Stack<String> stack1 = new Stack<>();
            Stack<String> stack2 = new Stack<>();

            for (int i = 0; i < key.length(); i++) {
                char c = key.charAt(i);
                if (c == '<') {
                    if (!stack1.isEmpty()) {
                        stack2.push(stack1.pop());
                    }
                }
                else if (c == '>') {
                    if (!stack2.isEmpty()) {
                        stack1.push(stack2.pop());
                    }
                }
                else if (c == '-') {
                    if (!stack1.isEmpty()) {
                        stack1.pop();
                    }
                }
                else {
                    stack1.push(String.valueOf(c));
                }
            }
            while(!stack2.isEmpty()){
                stack1.push(stack2.pop());
            }
            System.out.println(String.join("", stack1));
        }
    }
}