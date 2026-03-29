#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
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

void zigzagTraversal(struct Node* root) {
    if (!root) return;

    struct Node** currentLevel = (struct Node**)malloc(1000 * sizeof(struct Node*));
    struct Node** nextLevel = (struct Node**)malloc(1000 * sizeof(struct Node*));

    int currTop = -1, nextTop = -1;
    int leftToRight = 1;

    currentLevel[++currTop] = root;

    while (currTop >= 0) {
        struct Node* temp = currentLevel[currTop--];
        printf("%d ", temp->data);

        if (leftToRight) {
            if (temp->left) nextLevel[++nextTop] = temp->left;
            if (temp->right) nextLevel[++nextTop] = temp->right;
        } else {
            if (temp->right) nextLevel[++nextTop] = temp->right;
            if (temp->left) nextLevel[++nextTop] = temp->left;
        }

        if (currTop < 0) {
            leftToRight = !leftToRight;

            struct Node** tempArr = currentLevel;
            currentLevel = nextLevel;
            nextLevel = tempArr;

            currTop = nextTop;
            nextTop = -1;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    zigzagTraversal(root);

    return 0;
}