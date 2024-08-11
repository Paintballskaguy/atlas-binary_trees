#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node
 * @node: Pointer to the node to find the sibling
 *
 * Return: Pointer to the sibling node,
 * or NULL if no sibling exists or node is NULL
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	/* Check if the node is the left child */
	if (node->parent->left == node)
		return (node->parent->right);

	/* Otherwise, check if the node is the right child */
	if (node->parent->right == node)
		return (node->parent->left);

	/* If no sibling exists, return NULL */
	return (NULL);
}

/**
 * binary_tree_uncle - Finds the uncle of a node
 * @node: Pointer to the node to find the uncle
 *
 * Return: Pointer to the uncle node, or NULL if no uncle exists or node is NULL
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);

	/* The uncle is the sibling of the parent */
	return (binary_tree_sibling(node->parent));
}