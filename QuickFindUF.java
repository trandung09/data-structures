import java.io.*;
import java.util.*;

public class QuickFindUF {

    private int[] id;
    private int count;

    public QuickFindUF(int n) {
        if (n < 0) throw new IllegalArgumentException("n is negative");
        count = n;
        id = new int[n];

        for (int i=0 ; i<n ; i++) {
            id[i] = i;
        }
    }

    public int count() {
        return count;
    }

    public void validate(int p) {
        int n = id.length;
        if (p < 0 && p >= n) {
            throw new IllegalArgumentException("index " + p + " is not between 0 and " + (n-1));
        }
    }

    public int find(int p) {
        validate(p);
        return id[p];
    }

    public boolean connected(int p, int q) {
        return find(p) == find(q);
    }

    /**
     *  Merges the component containing site
     */
    public void union(int p, int q) {
        int pID = find(p);
        int qID = find(q);

        if (pID == qID) return;

        for (int i=0 ; i<id.length ; i++)
            if (id[i] == pID) id[i] = qID;

        count--;
    }

    public static void main(String[] args) throws IOException {

       File file = new File("D:/HOC KI 2 - 2024/BlueJSource/UnionFind/midUF.txt");
       Scanner sc = new Scanner(file);

       int n = sc.nextInt();

       QuickFindUF uf = new QuickFindUF(n);

       while(sc.hasNextInt()) {
           int p = sc.nextInt();
           int q = sc.nextInt();
           
           uf.union(p, q);
       }

        System.out.println("Result is " + uf.count() +  " components");

       sc.close();
    }
}
