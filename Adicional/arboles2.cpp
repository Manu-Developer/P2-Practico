#include <stdio.h>

struct nodeAB {
    int value;
    nodeAB *right;
    nodeAB *left;
};

typedef nodeAB *AB;

AB createNode(int value) {
    AB newNode = new nodeAB;
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void printTabs(int numtabs) {
    for (int i = 0; i < numtabs; i++) {
        printf("   ");
    }
}

void printTree_rec(AB tree, int level) {
    if (tree == NULL) {
        printTabs(level);
        printf("---Empty---");
        return;
    } else {
        printTabs(level);
        printf("value: %d\n", tree->value);
        printTabs(level);
        printf("left: ");

        printTree_rec(tree->left, level + 1);
        printTabs(level);
        printf("right: ");

        printTree_rec(tree->right, level + 1);
        printTabs(level);
    }
}

void printTree(AB tree) {
    printTree_rec(tree, 0);
}
int main() {
    AB node1 = createNode(10);
    AB node2 = createNode(11);
    AB node3 = createNode(12);
    AB node4 = createNode(13);
    AB node5 = createNode(14);

    node1->left = node2;
    node1->right = node3;
    node3->left = node4;
    node3->right = node5;

    printTree(node1);

    delete (node1);
    delete (node2);
    delete (node3);
    delete (node4);
    delete (node5);

    return 0;
}
