
namespace chapter12 {
    struct TreeNode {
        int value; // both the key and the data
        TreeNode *left;
        TreeNode *right;
    };

    class BinarySearchTree {
        private:
            TreeNode *root;

        public:
            BinarySearchTree(TreeNode *);
            // Insert a value into our tree
            void Insert(int);
            // Check if the tree contains a value
            auto Search(int) -> bool;
    };

    // Or, we can just do the BST implementation recursively
    auto Search(TreeNode*, int) -> bool;

    void PrintInOrder(TreeNode*);
}

