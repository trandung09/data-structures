package binarytree;

import java.util.Scanner;

public class BinarySearchTree {
    public static class node {
        private int keys;
        private int deep;
        private node left;
        private node right;

        public node() {
            this.deep = 0;
            this.left = null;
            this.right = null;
        }

        public node(int keys, int deep) {
            this.deep = deep;
            this.keys = keys;
            this.left = null;
            this.right = null;
        }

        public int getDeep() {
            return deep;
        }
        public void setDeep(int deep) {
            this.deep = deep;
        }
        public int getKeys() {
            return this.keys;
        }
        public void setKeys(int keys) {
            this.keys = keys;
        }
        public node getLeft() {
            return this.left;
        }
        public void setLeft(node left) {
            this.left = left;
        }
        public node getRight() {
            return this.right;
        }
        public void setRight(node right) {
            this.right = right;
        }

        public boolean hasLeft(){ return this.left != null; }
        public boolean hasRight(){ return this.right != null; }
    }

    public static class tree {
        public node root;
        private int num;

        public tree() {
            this.root = null;
            this.num = 0;
        }

        public node getRoot() {
            return this.root;
        }

        public int getNum() {
            return this.num;
        }

        public void add(node Node, int keys, node next) {
            if (root == null) {
                root = new node(keys, 0);
                num++;
                return;
            }
            if (Node == null) {
                if (next.getKeys() > keys)
                    next.setLeft(new node(keys, next.getDeep() + 1));
                else if (next.getKeys() < keys)
                    next.setRight(new node(keys, next.getDeep() + 1));
                num++;
            } else {
                if (Node.getKeys() > keys) add(Node.getLeft(), keys, Node);
                else if (Node.getKeys() == keys) {
                } else add(Node.getRight(), keys, Node);
            }
        }

        public void inOrder(node Node) {
            if (Node != null) {
                inOrder(Node.getLeft());
                System.out.println(Node.getKeys() + " " + Node.getDeep());
                inOrder(Node.getRight());
            }
        }

        public void preOrder(node Node) {
            if (Node != null) {
                System.out.println(Node.getKeys() + " " + Node.getDeep());
                inOrder(Node.getLeft());
                inOrder(Node.getRight());
            }
        }

        public void postOrder(node Node) {
            if (Node != null) {
                inOrder(Node.getLeft());
                inOrder(Node.getRight());
                System.out.println(Node.getKeys() + " " + Node.getDeep());
            }
        }
    }

}
