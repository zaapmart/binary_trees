#include "binary_trees.h"

/**
 * binary_tree_postorder - Goes through a binary tree using post-order
 * traversal.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 *        The value in the node must be passed as a parameter to this
 *        function.
 *
 * Description: In post-order traversal, we recursively do a post-order
 * traversal of the left subtree, then recursively do a post-order
 * traversal of the right subtree, and finally visit the root node.
 *
 * Return: void
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	/* Recursively traverse the left subtree */
	binary_tree_postorder(tree->left, func);

	/* Recursively traverse the right subtree */
	binary_tree_postorder(tree->right, func);

	/* Call the function on the current node */
	func(tree->n);
}

