#include<iostream>
#include<stdio.h>
static const int MAX = 100;

// 各計算ステップで1つの最小値を「選択」していく

void printLine (int A[], int N) {
    for (int i = 0; i < N; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", A[i]);
    }
    printf("\n");
}

int selectionSort(int A[], int N, int idx, int acc) {
    int min = -1;
    int minIdx = -1;
    for (int i = idx; i < N; i++) {
        if (i == idx) {
            min = A[i];
            continue;
        }
        int right = A[i];
        if (right < min) {
            min = right;
            minIdx = i;
        }
    }
    
    int cnt = 0;
    if (minIdx > -1 && minIdx != idx) {
        int v = A[idx];
        A[idx] = min;
        A[minIdx] = v;
        cnt = 1;
    }
    
    idx++;
    if (idx < N-1) {
        cnt = selectionSort(A, N, idx, cnt);
    }
    return acc + cnt;
}

int main() {
    int N;
    scanf("%d", &N);
    
    int A[MAX];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    int r = selectionSort(A, N, 0, 0);
    printLine(A, N);
    printf("%d\n", r);
   
    return 0;
}

