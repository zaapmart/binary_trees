#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left-child of another node
 * @parent: A pointer to the parent node.
 * @value: The value to store in the new node.
 *
 * Return: If memory allocation fails or parent is NULL - NULL.
 *         Otherwise - a pointer to the created node.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
    binary_tree_t *new_node;

    /* Check if parent is NULL */
    if (parent == NULL)
        return (NULL);

    /* Allocate memory for the new node */
    new_node = malloc(sizeof(binary_tree_t));
    if (new_node == NULL)
        return (NULL);

    /* Assign the value to the new node */
    new_node->n = value;

    /* Set the parent of the new node */
    new_node->parent = parent;

    /* If parent already has a left child */
    if (parent->left != NULL)
    {
        /* Set the left child of the new node to the current left child */
        new_node->left = parent->left;
        /* Set the parent of the current left child to the new node */
        parent->left->parent = new_node;
    }
    else
    {
        /* If parent doesn't have a left child, set new node's left child to NULL */
        new_node->left = NULL;
    }

    /* Set the left child of the parent to the new node */
    parent->left = new_node;

    /* Set the right child of the new node to NULL */
    new_node->right = NULL;

    /* Return a pointer to the new node */
    return (new_node);
}
