#pragma once

#include <stdio.h>
#include <stdlib.h>

#define INTCMP(x,y) (((x)>(y))?1:(((x)==(y))?0:1))

typedef struct node_ *nodePtr;
typedef struct node_ {
	int key;				
	nodePtr left, right;
	//struct node_ *left, *right;
}node;

nodePtr binRoot;

nodePtr createNode(int key) {
	nodePtr newNode = (nodePtr)malloc(sizeof(node));

	newNode->key = key;
	newNode->left = newNode->right = NULL;

	return newNode;
}

/* recursive version */
/*
requirements:
	1. deleteNode
	2. printNode levelwise
	3. 

*/
nodePtr insertNodeRecur(nodePtr root, int key) {
	if (!root)
		return createNode(key);

	switch (INTCMP(key, root->key)) {
	case -1:
		root->left = insertNodeRecur(root->left, key);
	case 0:
		return NULL;
	case 1:
		root->right = insertNodeRecur(root->right, key);
	}
}

void printTree(nodePtr root) {
	if (!root)
		return;

	printTree(root->left);
	printf("%d ", root->key);
	printTree(root->right);
}

void demolishTreeRecur(nodePtr root) {
	if (!root)
		return;

	demolishTreeRecur(root->left);
	demolishTreeRecur(root->right);
	free(root);
}