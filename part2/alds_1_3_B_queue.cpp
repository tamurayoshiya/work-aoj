#include <cstdlib>
#include<iostream>
#include<stdio.h>
using namespace std;
static const int N_MAX = 1000000;
static const int LEN_P_NAME = 10;

struct Node {
    char name[LEN_P_NAME];
    int time; 
    bool active;
    Node *left;
    Node *right;
};

struct Node *nil = (Node *)malloc(sizeof(Node));
struct Node *QUEUE;
struct Node *LAST_NODE;
int QUEUE_LEN = 0;

int len(Node *queue) {
    if (queue == nil || !queue->active) {
        return 0;
    }
    return QUEUE_LEN;
}

Node* last(Node *queue) {
    return LAST_NODE;
}

Node* head() {
    return QUEUE;
}

Node* tail() {
    return last(QUEUE);
}

Node* create() {
    struct Node *q = (Node *)malloc(sizeof(Node));
    q->left = nil;
    q->right = nil;
    return q;
}

void enqueue(char name[LEN_P_NAME], int time)
{
    Node *q = create();
    
    int l = len(QUEUE);
    QUEUE_LEN++;
    if (l == 0) {
        q = QUEUE;
    }
    
    for (int i = 0; i < LEN_P_NAME; i++) {
        q->name[i] = name[i];
    }
    q->time = time;
    q->active = true;
    
    if (l > 0) {
        Node *last = tail();
        last->right = q;
        q->left = last;
        LAST_NODE = q;
    }
}

void dequeue()
{
    if (len(QUEUE) == 0) {
        return;
    }
    QUEUE_LEN--;
    Node *h = head();
    QUEUE = h->right;
}

void initQueue()
{
    Node *q = create();
    QUEUE = q;
    LAST_NODE = q;
}

int main()
{
    // Scan first line
    int n;
    scanf("%d", &n);
    
    int quantum;
    scanf("%d", &quantum);
    
    // Init queue
    initQueue();
    
    // Scan rows and build queue
    for (int i = 0; i < n; i++) {
        char name[10];
        int time;
        scanf("%s %d", name, &time);
        enqueue(name, time);
    }
    
    // Start Round-Robin
    int l = len(QUEUE);
    int rest = 0;
    int time = 0;
    while(l > 0) {
        Node *h = head();
        rest = h->time - quantum;
        if (rest > 0) {
            // Reschedule
            dequeue();
            enqueue(h->name, rest);
            time += quantum;
            continue;
        }
        
        time += h->time;
        printf("%s %d\n", h->name, time);
        dequeue();

        l = len(QUEUE);
    }
  
    return 0;
}

