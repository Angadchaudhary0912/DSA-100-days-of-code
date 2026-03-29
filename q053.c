#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int hd;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->hd = 0;
    node->left = node->right = NULL;
    return node;
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node** queue = (struct Node**)malloc(n * sizeof(struct Node*));
    int front = 0, rear = 0;

    struct Node* root = newNode(arr[0]);
    queue[rear++] = root;

    int i = 1;
    while (i < n) {
        struct Node* temp = queue[front++];

        if (arr[i] != -1) {
            temp->left = newNode(arr[i]);
            queue[rear++] = temp->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            temp->right = newNode(arr[i]);
            queue[rear++] = temp->right;
        }
        i++;
    }
    return root;
}

void findMinMax(struct Node* root, int* min, int* max, int hd) {
    if (!root) return;

    if (hd < *min) *min = hd;
    if (hd > *max) *max = hd;

    findMinMax(root->left, min, max, hd - 1);
    findMinMax(root->right, min, max, hd + 1);
}

void printVerticalLine(struct Node* root, int line_no, int hd) {
    if (!root) return;

    if (hd == line_no)
        printf("%d ", root->data);

    printVerticalLine(root->left, line_no, hd - 1);
    printVerticalLine(root->right, line_no, hd + 1);
}

void verticalOrder(struct Node* root) {
    int min = 0, max = 0;
    findMinMax(root, &min, &max, 0);

    for (int i = min; i <= max; i++) {
        printVerticalLine(root, i, 0);
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}