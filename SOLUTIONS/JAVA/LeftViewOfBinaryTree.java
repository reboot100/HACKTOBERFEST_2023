import java.util.ArrayList;
import java.util.LinkedList;

class Node {
    int data;
    Node left, right;

    Node(int item) {
        data = item;
        left = right = null;
    }
}

public class LeftViewOfBinaryTree {
    ArrayList<Integer> leftView(Node root) {
        ArrayList<Integer> ans = new ArrayList<>();
        if (root == null) return ans;
        LinkedList<Node> que = new LinkedList<>();
        que.addLast(root);
        while (que.size() != 0) {
            int size = que.size();
            ans.add(que.getLast().data);
            while (size-- > 0) {
                Node rNode = que.removeFirst();

                if (rNode.right != null) que.addLast(rNode.right);
                if (rNode.left != null) que.addLast(rNode.left);
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.right = new Node(4);
        root.right.left = new Node(5);
        root.right.right = new Node(6);

        LeftViewOfBinaryTree tree = new LeftViewOfBinaryTree();

        ArrayList<Integer> leftViewList = tree.leftView(root);

        System.out.println("Left View of the Binary Tree: " + leftViewList);
    }
}
