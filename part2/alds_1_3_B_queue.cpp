#include<iostream>
#include<stdio.h>
using namespace std;
static const int N_MAX = 1000000;

struct Node {
    char name[10];
    int time; 
    Node *left;
    Node *right;
};

struct Node QUEUE;

int len(Node *queue) {
    if (!queue->right) {
        return 0;
    }
    return 1 + len(queue->right);
}

Node* walk(Node *queue) {
    if (queue->right) {
        return walk(queue->right);
    }
    return queue;
}

Node* last(Node *queue) {
    if (!queue->right) {
        return queue;
    }
    return walk(queue);
}

Node* head() {
    return &QUEUE;
}

Node* tail() {
    return last(&QUEUE);
}

void enqueue(char name[10], int time) {
    struct Node *q = (Node *)malloc(sizeof(Node));
    for (int i = 0; i < 10; i++) {
        q->name[i] = name[i];
    }
    q->time = time;
    
    Node *last = tail();
    last->right = q;
    q->left = last;
}

int main()
{
    // Scan first line
    int n;
    scanf("%d", &n);
    
    int quantum;
    scanf("%d", &quantum);
    
    // Scan rows and build queue
    for (int i = 0; i < n; i++) {
        char name[10];
        int time;
        scanf("%s %d", name, &time);
        if (i == 0) {
            for (int j = 0; j < 10; j++) {
                QUEUE.name[j] = name[j];
            }
            QUEUE.time = time;
            continue;
        }
        enqueue(name, time);
    }
    
    // Start Round-Robin
    int cnt = len(&QUEUE);
    printf("%d\n", cnt);
    
    Node *first = head();
    printf("%s %d\n", first->name, first->time);
    
    Node *last = tail();
    printf("%s %d\n", last->name, last->time);
  
    return 0;
}

