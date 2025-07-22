#include <stdio.h>
#include <stdlib.h>
#define MAX 100
// Định nghĩa Node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;
// Khai báo cấu trúc Queue
typedef struct Queue{
    Node* data[MAX];  // Phần dữ liệu
    int front;
    int rear;
} Queue;

// Khai báo hàng đợi rỗng
void initialQueue(Queue* q){
    q->front = q->rear = 0;
}

// Kiểm tra hàng đơi rỗng
int isEmpty(Queue* q){
    return q->front == q->rear;
}

// Hàm thêm phần tử vào trong hàng đợi
void enqueue(Queue* q, Node* node){
    if (q->rear < MAX){
        q->data[q->rear++] = node;
    }
}

// Lấy phần tử ra khỏi hàng đợi
Node* dequeue(Queue* q){
    if (!isEmpty(q)){
        return q->data[q->front++];
    }

    return NULL;
}
// Tạo Node mới
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Loi cap phat \n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Hàm duyệt theo thứ tự Preorder
void preorder(Node* root) {
    if (root == NULL){
        printf(" NULL ->");
        return;
    }

    printf(" %d ->", root->data);         // In dữ liệu node
    preorder(root->left);     // Duyệt trái
    preorder(root->right);    // Duyệt phải
}
// Hàm thêm phần tử vào cây
void insertNode(Node*root,int value) {
    if (root==NULL) {
        return;
    }
    Queue q;
    initialQueue(&q);
    enqueue(&q,root);
    while(!isEmpty(&q)) {
        Node*current=dequeue(&q);
        if (current->left==NULL) {
            current->left=createNode(value);
            return;
        }else {
            enqueue(&q,current->left);
        }
        if (current->right==NULL) {
            current->right=createNode(value);
            return;
        }else {
            enqueue(&q,current->right);
        }
    }
}
int findMaxValue(Node* root) {
    // Kiểm tra cây rỗng
    if (root == NULL) {
        return 0;
    }

    int maxLeft = findMaxValue(root->left);   // Tìm max bên trái
    int maxRight = findMaxValue(root->right); // Tìm max bên phải

    // So sánh giữa node hiện tại, trái và phải
    int max = root->data;
    // So sánh node hiện tại với node trái
    if (maxLeft > max){
        max = maxLeft; // Cập nhật giá trị lớn nhất là trái
    }
    // So sánh node hiện tại với node phải
    if (maxRight > max){
        max = maxRight; // Cập nhật giá trị lớn nhất là trái
    }
    // Trả về giá trị lớn nhất
    return max;
}
int main() {
    // Tạo các node
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);
    // In kết quả
    printf("max value: %d",findMaxValue(root));
    free(root);
    return 0;
}
