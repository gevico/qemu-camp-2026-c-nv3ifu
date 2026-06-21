#include "simple_tree.h"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

Queue* create_queue() {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue *q, TreeNode *tree_node) {
    QueueNode *p = malloc(sizeof(*p)); if (!p) return; p->tree_node = tree_node; p->next = NULL;
    if (q->rear) q->rear->next = p; else q->front = p; q->rear = p;
}

TreeNode* dequeue(Queue *q) {
    if (!q || !q->front) return NULL; QueueNode *p = q->front; TreeNode *node = p->tree_node; q->front = p->next; if (!q->front) q->rear = NULL; free(p); return node;
}

bool is_empty(Queue *q) {
    return q->front == NULL;
}

void free_queue(Queue *q) {
    while (!is_empty(q)) {
        dequeue(q);
    }
    free(q);
}

TreeNode* build_tree_by_level(int *level_order, int size) {
    if (!level_order || size <= 0 || level_order[0] == INT_MIN) return NULL;
    TreeNode *root = calloc(1, sizeof(*root)); if (!root) return NULL; root->val = level_order[0];
    Queue *q = create_queue(); if (!q) { free(root); return NULL; } enqueue(q, root);
    int i = 1;
    while (i < size && !is_empty(q)) {
        TreeNode *parent = dequeue(q);
        if (i < size && level_order[i] != INT_MIN) { parent->left = calloc(1, sizeof(*parent->left)); parent->left->val = level_order[i]; enqueue(q, parent->left); } i++;
        if (i < size && level_order[i] != INT_MIN) { parent->right = calloc(1, sizeof(*parent->right)); parent->right->val = level_order[i]; enqueue(q, parent->right); } i++;
    }
    free_queue(q); return root;
}

void preorder_traversal(TreeNode *root) {
    if (!root) return; printf("%d ", root->val); preorder_traversal(root->left); preorder_traversal(root->right);
}

void preorder_traversal_iterative(TreeNode *root) {
    if (!root) return; TreeNode **stack = malloc(128 * sizeof(*stack)); if (!stack) return; size_t top = 0; stack[top++] = root;
    while (top) { TreeNode *node = stack[--top]; printf("%d ", node->val); if (node->right) stack[top++] = node->right; if (node->left) stack[top++] = node->left; } free(stack);
}

void free_tree(TreeNode *root) {
    if (root == NULL) {
        return;
    }
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}
