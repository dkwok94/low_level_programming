#include "binary_trees.h"

/**
 *subtreenodecount - counts the number of nodes in a subtree
 *@tree: a pointer to the tree to count
 *@count: the number of nodes
 *
 *Return: the number of nodes in the subtree
 */

size_t subtreenodecount(const binary_tree_t *tree, size_t count)
{
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if (tree->left != NULL)
		return (count + subtreenodecount(tree->left, count));
	if (tree->right != NULL)
		return (count + subtreenodecount(tree->right, count));
	return (count);
}

/**
 *binary_tree_size - measures the size of a binary tree
 *@tree: a pointer to the tree to measure the size of
 *
 *Return: the size of the tree or 0 if tree is NULL
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t counter = 0;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if (tree->left != NULL)
		counter = subtreenodecount(tree->left, 1);
	if (tree->right != NULL)
		counter += subtreenodecount(tree->right, 1);

	return (counter + 1);
}
