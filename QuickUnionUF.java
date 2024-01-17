import java.io.*;
import java.util.*;

public class QuickUnionUF
{
    private int count;
    private int[] parent;

    public QuickUnionUF(int n) {
        if (n < 0) throw new IllegalArgumentException("n is negative");
        count = n;
        parent = new int[n];

        for (int i=0 ; i<n ; i++) {
            parent[i] = i;
        }
    }

    public int count() {
        return count;
    }

    public void validate(int p) {
        int n = parent.length;
        if (p < 0 || p >= n) {
            throw new IllegalArgumentException("index " + p + " is not between 0 and " + (n-1));
        }
    }

    public int find(int p) {
        validate(p);

        while(p != parent[p]) {
            p = parent[p];
        }

        return p;
    }

    public boolean connected(int p, int q) {
        return find(p) == find(q);
    }

    public void union(int p, int q) {

        int rootP = find(p);
        int rootQ = find(q);

        if (rootP == rootQ) return;

        parent[rootP] = rootQ;
        count--;
    }

    public static void main(String[] args) throws IOException {
        File file = new File("D:/HOC KI 2 - 2024/BlueJSource/UnionFind/midUF.txt");
        Scanner sc = new Scanner(file);

        int n = sc.nextInt();

        QuickUnionUF uf = new QuickUnionUF(n);

        while(sc.hasNextInt()) {
            int p = sc.nextInt();
            int q = sc.nextInt();

            uf.union(p, q);
        }

        System.out.println("Result is " + uf.count() + " components");

        sc.close();
    }
}
