#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
struct TreeNode {
    char name;
    struct TreeNode* left;
    struct TreeNode* right;
};
struct TreeNode* createNode(char name) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->name = name;
    newNode->left = newNode->right = NULL;
    return newNode;
}
bool findPath(struct TreeNode* root, char name, char path[], int pathIndex) {
    if (root == NULL)
        return false;

    path[pathIndex] = root->name;
    pathIndex++;

    if (root->name == name)
        return true;

    if (findPath(root->left, name, path, pathIndex) || findPath(root->right, name, path, pathIndex))
        return true;

    return false;
}
void printTreeDiagram(struct TreeNode* root, int depth) {
    if (root == NULL)
        return;
    printf("   ");
    for (int i = 0; i < depth; i++) {
        if (i > 0) {
            if (i % 2 == 0) {
                printf("   ");
            } else {
                printf("|  ");
            }
        }
    }
    printf("|--NODE %c\n", root->name);

    printTreeDiagram(root->left, depth + 1);
    printTreeDiagram(root->right, depth + 1);
}
void findShortestPath(struct TreeNode* root, char node1, char node2) {
    char path1[100], path2[100];
    int path1Index = 0, path2Index = 0;

    if (!findPath(root, node1, path1, path1Index) || !findPath(root, node2, path2, path2Index)) {
        printf("Nodes not found in the tree.\n");
        return;
    }

    printf("Shortest Path between NODE %c and NODE %c:\n", node1, node2);

    for (int i = 0; i < path1Index && i < path2Index; i++) {
        if (path1[i] == path2[i]) {
            printf("   NODE %c\n", path1[i]);
        } else {
            printf("   NODE %c\n   |\n", path1[i]);
        }
    }
    printf("Tree Diagram:\n");
    printTreeDiagram(root, 0);
}
int main() {
    struct TreeNode* root = createNode('1');
    root->left = createNode('2');
    root->right = createNode('3');
    root->left->left = createNode('4');
    root->left->right = createNode('5');
    root->right->left = createNode('6');
    root->right->right = createNode('7');

    findShortestPath(root, '2', '5'); 

    return 0;
}
