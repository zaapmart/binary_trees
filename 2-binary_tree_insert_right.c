#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as the right-child of another node.
 * @parent: A pointer to the parent node.
 * @value: The value to store in the new node.
 *
 * Return: If memory allocation fails or if parent is NULL - NULL.
 *         Otherwise - a pointer to the newly created node.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
    binary_tree_t *new_node;

    if (!parent)
        return (NULL);

    new_node = malloc(sizeof(binary_tree_t));
    if (!new_node)
        return (NULL);

    new_node->n = value;
    new_node->parent = parent;
    new_node->left = NULL;

    if (parent->right)
    {
        new_node->right = parent->right;
        parent->right->parent = new_node;
    }
    else
    {
        new_node->right = NULL;
    }

    parent->right = new_node;

    return (new_node);
}

