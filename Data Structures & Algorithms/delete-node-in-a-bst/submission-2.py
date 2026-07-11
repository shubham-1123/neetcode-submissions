# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def find_successor(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        while root and root.left:
            root = root.left
        return root

    def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
        if root is None:
            return None
        if key < root.val:
            root.left = self.deleteNode(root.left, key)
        elif key > root.val:
            root.right = self.deleteNode(root.right, key)
        else:
            if root.left is None and root.right is None:
                root = None
                return None
            elif root.left is None or root.right is None:
                temp: Optional[TreeNode] = root.left if (root.left) else root.right
                root = None
                return temp
            else :
                temp : Optional[TreeNode] = self.find_successor(root.right)
                root.val = temp.val
                root.right = self.deleteNode(root.right, temp.val)
        return root