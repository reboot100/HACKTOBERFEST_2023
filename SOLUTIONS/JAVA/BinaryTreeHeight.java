class TreeNode {
    int data;
    TreeNode left;
    TreeNode right;

    public TreeNode(int data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

class BinaryTree {
    TreeNode root;

    public int findHeight(TreeNode node) {
        if (node == null) {
            return -1;
        } else {
            int leftHeight = findHeight(node.left);
            int rightHeight = findHeight(node.right);
            return Math.max(leftHeight, rightHeight) + 1;
        }
    }
}

public class BinaryTreeHeight {
    public static void main(String[] args) {
        BinaryTree bst = new BinaryTree();
        
        bst.root = new TreeNode(50);
        bst.root.left = new TreeNode(30);
        bst.root.right = new TreeNode(70);
        bst.root.left.left = new TreeNode(20);
        bst.root.left.right = new TreeNode(40);
        bst.root.right.left = new TreeNode(60);
        bst.root.right.right = new TreeNode(80);

        int height = bst.findHeight(bst.root);
        System.out.println("Height of the BST is: " + height);
    }
}
