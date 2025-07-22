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
// Hàm duyệt theo thứ tự Postorder
void postorder(Node* root) {
    if (root == NULL){
        printf(" NULL ->");
        return;
    }

    postorder(root->left);    // Duyệt cây con trái
    postorder(root->right);   // Duyệt cây con phải
    printf(" %d ->", root->data);   // Duyệt gốc
}
// Duyệt theo thứ tự Inorder
void inorder(Node* root) {
    if (root == NULL){
        printf(" NULL ->");
        return;
    }

    inorder(root->left);    // Duyêt cây trái
    printf(" %d ->", root->data); // Duyệt cây gốc
    inorder(root->right);   // Duyệt cây phải
}
// Duyệt theo levelorder
void levelOrder(Node* root){
    // Kiểm tra xem tree có phần tử không
    if (root == NULL) {
        return;
    }

    Queue q;

    // Gọi hàm khởi tạo queue
    initialQueue(&q);

    // Bât đầu từ phần gốc
    enqueue(&q, root);

    // Duyệt
    while (!isEmpty(&q)){
        // Lấy node từ queue ra
        Node* currentNode = dequeue(&q);

        // In ra node hiện tại
        printf(" %d -> ", currentNode->data);

        // Nếu có con bên trái, thêm vào trong queue
        if (currentNode->left){
            enqueue(&q, currentNode->left);
        }
        else{
            printf(" NULL ->");
        }

        // Nếu có con bên phải, thêm vào trong queue
        if (currentNode->right){
            enqueue(&q, currentNode->right);
        }
        else{
            printf(" NULL ->");
        }

    }

}
int main() {
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    printf("Duyet theo thu tu Preorder: ");
    preorder(root);  // Gọi hàm duyệt cây
    printf("\n");
    printf("Duyet theo thu tu Postorder: ");
    postorder(root);  // Gọi hàm duyệt cây
    printf("\n");
    printf("Duyet theo thu tu Inorder: ");
    inorder(root);  // Gọi hàm duyệt cây
    printf("\n");
    printf("Duyet theo thu tu Levelorder: ");
    levelOrder(root);  // Gọi hàm duyệt cây
    // Giải phóng bộ nhớ
    free(root->left->left);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}