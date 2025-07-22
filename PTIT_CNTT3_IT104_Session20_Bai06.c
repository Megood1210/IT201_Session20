#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// Định nghĩa Node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Cấu trúc Queue để duyệt theo tầng khi cần
typedef struct Queue {
    Node* data[MAX];
    int front;
    int rear;
} Queue;

// Khởi tạo hàng đợi rỗng
void initialQueue(Queue* q) {
    q->front = q->rear = 0;
}

// Kiểm tra hàng đợi rỗng
int isEmpty(Queue* q) {
    return q->front == q->rear;
}

// Thêm phần tử vào hàng đợi
void enqueue(Queue* q, Node* node) {
    if (q->rear < MAX) {
        q->data[q->rear++] = node;
    }
}

// Lấy phần tử ra khỏi hàng đợi
Node* dequeue(Queue* q) {
    if (!isEmpty(q)) {
        return q->data[q->front++];
    }
    return NULL;
}

// Tạo một node mới
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Lỗi cấp phát bộ nhớ!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
// Duyệt cây theo thứ tự trước (Preorder)
void preorder(Node* root) {
    if (root == NULL) return;

    printf("%d -> ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// 🔍 Hàm tìm tầng (level) của node có giá trị value
int findLevel(Node* root, int value, int level) {
    // Kiểm tra cây rỗng
    if (root == NULL){
        return -1;
    }

    // Kiểm node hiện tại là giá trị cần tìm
    if (root->data == value){
        return level;
    }

    // Gọi đệ quy tìm bên trái, tăng tầng thêm 1
    int leftLevel = findLevel(root->left, value, level + 1);

    // Kiểm tra trái có giá trị cần tìm
    if (leftLevel != -1){
        return leftLevel;
    }

    // Kiểm tra phải có giá trị cần tìm
    return findLevel(root->right, value, level + 1);
}

// Chương trình chính
int main() {
    // Tạo cây nhị phân mẫu
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);
    // In cây
    printf("Duyet cay theo Preorder: ");
    preorder(root);
    printf("NULL\n");

    // Nhập giá trị cần tìm tầng
    int target;
    printf("\nNhap gia tri can tim tang: ");
    scanf("%d", &target);

    // Tìm tầng của giá trị nhập
    int level = findLevel(root, target, 0);
    if (level == -1)
        printf("Khong co gia tri %d trong cay\n", target);
    else
        printf("Node level: %d", level);

    return 0;
}