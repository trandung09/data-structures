import java.io.*;
import java.util.*;

public class UF
{
    private int count;
    private int[] parent;
    private int[] rank;

    public UF(int n) {
        if (n < 0) throw new IllegalArgumentException("n is negative");
        count = n;
        parent = new int[n];
        rank = new int[n];

        for (int i=0 ; i<n ; i++) {
            parent[i] = i;
            rank[i] = 0;
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

        if (parent[p] != p) {
            parent[p] = find(parent[p]); // path compression
        }
        return parent[p];
    }

    public boolean connected(int p, int q) {
        return find(p) == find(q);
    }

    public void union(int p, int q) {

        int rootP = find(p);
        int rootQ = find(q);

        if (rootP == rootQ) return;
        
        if (rank[rootP] < rank[rootQ]) {
            parent[rootP] = rootQ;
        } else if (rank[rootP] > rank[rootQ]) {
            parent[rootQ] = rootP;
        } else {
            parent[rootQ] = rootP;
            rank[rootP]++;
        }
        
        count--;
    }

    public static void main(String[] args) throws IOException {
        File file = new File("D:/HOC KI 2 - 2024/BlueJSource/UnionFind/tinyUF.txt");
        
        Scanner sc = new Scanner(file);

        int n = sc.nextInt();

        UF uf = new UF(n);

        while(sc.hasNextInt()) {
            int p = sc.nextInt();
            int q = sc.nextInt();

            System.out.println(p + " " + q);
            uf.union(p, q);
        }

        System.out.println("Result is " + uf.count() + " components");

        sc.close();
    }
}
