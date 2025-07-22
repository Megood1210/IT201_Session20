#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc một node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Hàm tạo node mới với dữ liệu cho trước
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Loi cap phat\n");
        exit(1);
    }

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

int main() {
    // Tạo các node
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    // Kiểm tra in ra một số node
    printf("Root: %d\n", root->data);
    printf("Root->Left: %d\n", root->left->data);
    printf("Root->Right: %d\n", root->right->data);
    printf("Root->Right->Left: NULL\n");
    printf("Root->Right->Right: NULL\n");
    printf("Root->Left->Left: %d\n", root->left->left->data);
    printf("Root->Left->Left->Left: NULL\n");
    printf("Root->Left->Left->Right: NULL\n");



    // Giải phóng bộ nhớ sau khi sử dụng (nên thêm code để giải phóng toàn bộ cây)
    free(root->left->left);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}