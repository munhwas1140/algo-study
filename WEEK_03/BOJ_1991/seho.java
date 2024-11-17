package week3.BOJ1991;

import java.util.*;
import java.io.*;

class Node {
    char name;
    Node left, right;

    Node(char name) {
        this.name = name;
    }
}

public class seho {

    public static void insert(Node t, char name, char left, char right) {
        if (t.name == name) {
            if (left != '.') {
                t.left = new Node(left);
            }
            if (right != '.') {
                t.right = new Node(right);
            }
        } else {
            if (t.left != null) {
                insert(t.left, name, left, right);
            }
            if (t.right != null) {
                insert(t.right, name, left, right);
            }
        }

    }

    static Node root = new Node('A');

    static void preOrder(Node t) {
        if (t == null) return;
        System.out.print(t.name);
        preOrder(t.left);
        preOrder(t.right);
    }

    static void inOrder(Node t) {
        if (t == null) return;
        inOrder(t.left);
        System.out.print(t.name);
        inOrder(t.right);
    }

    static void postOrder(Node t) {
        if (t == null) return;
        postOrder(t.left);
        postOrder(t.right);
        System.out.print(t.name);
    }

    public static void main(String[] args) throws IOException{

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            char a = st.nextToken().charAt(0);
            char b = st.nextToken().charAt(0);
            char c = st.nextToken().charAt(0);
            insert(root, a, b, c);
        }
        preOrder(root);
        System.out.println();
        inOrder(root);
        System.out.println();
        postOrder(root);
    }
}
