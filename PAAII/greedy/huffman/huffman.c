#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char c;
    int freq;
    struct Node *left, *right;
} Node;

/**
 * Functions to concatenate or print an array's elements
 * Params:
 *      int/char *a: a pointer to the array
 *      int n: the size of the array
 * return: NULL
*/
void print(int *a, int n) {
    for (int i = 0; i < n; i++) printf("%d", a[i]);
    printf("\n");
}

void printIntArray(int *a, int n) {
    printf("[%d", a[0]);
    for (int i = 1; i < n; i++) printf(", %d", a[i]);
    printf("]\n");
}

void printCharArray(char *a, int n) {
    printf("[%c", a[0]);
    for (int i = 1; i < n; i++) printf(", %c", a[i]);
    printf("]\n");
}


/**
 * Function to check if a Tree's Node is leaf
 * Params:
 *      Node *node: a pointer to the node
 * return: 0 (false) 1 (true)
*/
int isLeaf(Node *node) { return node->left == NULL && node->right == NULL; }


/**
 * Function to swap two nodes inside the priority queue
 * Params:
 *      Node *nd1, *nd2: nodes to be swapped 
 * return: NULL
*/
void swapNode(Node *nd1, Node *nd2) {
    Node temp = *nd2;
    *nd2 = *nd1;
    *nd1 = temp; 
}


/**
 * Function to enqueue a Node
 * Params:
 *      Node **a: Queue of nodes
 *      int *len: size of the queue
 *      int n: max size of the queue
 *      Node *element: node to be inserted
 * return: NULL
*/
void insertQueue(Node **a, int *len, int n, Node *element) {
    if (*len == n) {
        printf("Queue is full\n");
        return;
    }
    a[(*len)++] = element;
}


/**
 * Function to extract the node with the minimum frequency of the queue
 * Params:
 *      Node **a: Queue of nodes
 *      int *len: size of the queue
 * return: the node with the minimum frequency of the queue
*/
Node *extractMin(Node **a, int *len) {
    int minimumIndex = 0;
    for (int i = 0; i < *len; i++) {
        if (a[i]->freq < a[minimumIndex]->freq) minimumIndex = i;
    }

    // swapping the minimum frequency node with the last node and removing it
    swapNode(a[minimumIndex], a[*len - 1]);
    (*len)--;  
    return a[*len];
}


/**
 * Function to make the Huffman Tree
 * Params:
 *      char *c: array of characters
 *      int *freq: array of char frequencies
 *      int n: number of characters
 * return: the root of the tree
*/
Node *huffmanTree(char *c, int *freq, int n) {
    // Allocating memory for a Priority Queue which will receive Node type pointers
    Node **queue = (Node **) malloc(n * sizeof(Node *));
    int qsize = 0;

    for (int i = 0; i < n; i++) {
        // node that will be placed whitin the queue
        Node *node = (Node *) malloc(sizeof(Node)); 
        node->c = c[i];
        node->freq = freq[i];
        node->left = node->right = NULL;

        // inserting in the queue
        insertQueue(queue, &qsize, n, node);
    }

    for (int i = 0; i < n - 1; i++) {
        // Extracting the minimum frequencies
        Node *x = extractMin(queue, &qsize);
        Node *y = extractMin(queue, &qsize);

        // Creating a new node which will receive the sum of the minimum frequencies
        Node *node = (Node *) malloc(sizeof(Node));

        node->freq = x->freq + y->freq;
        node->left = x;
        node->right = y;

        insertQueue(queue, &qsize, n, node);
    }
    return extractMin(queue, &qsize);
}


// Based on Geeks for Geeks' printCodes function
// https://www.geeksforgeeks.org/huffman-coding-greedy-algo-3/
/**
 * Function to print the code for each character
 * Params:
 *      Node *root: Huffman Tree's root
 *      int *a: array of bits
 *      int i: index of the array
 * return: NULL
*/
void printBits(Node *root, int *a, int i) {
    // bit 0 to the left characters
    if (root->left != NULL) {
        a[i] = 0;
        printBits(root->left, a, i + 1);
    }

    // bit 1 to the right characters
    if (root->right != NULL) {
        a[i] = 1;
        printBits(root->right, a, i + 1);
    }

    if (isLeaf(root)) {
        printf("- %c: ", root->c);
        print(a, i);
    }
}


int main() {
    int n = 6;
    char *c = "abcdef";
    int freq[] = {45, 13, 12, 16, 9, 5};

    printf("Characters: "); printCharArray(c, n);
    printf("Frequencies: "); printIntArray(freq, n);

    Node *root = huffmanTree(c, freq, n);
    printf("Characters Code:\n");

    int *a = (int *) malloc(n * sizeof(int));
    printBits(root, a, 0);

    free(a);
    return 0;
}