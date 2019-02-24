#include<iostream>
#include<stdio.h>
static const int MAX = 100;
    
// 順番が逆になっている隣接要素がなくなるまで、次の処理を繰り返す
// -> 配列の末尾から隣接する要素を順番に比べていき、大小関係が逆ならば交換する。

void writeLine (int A[], int N) {
    for (int i = 0;i < N;i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", A[i]);
    }
    printf("\n");
}

int bubbleSort(int A[], int N, int acc) {
    int cnt = 0;
    for (int i = N - 1;i > 0;i--) {
        int r = A[i];
        int l = A[i - 1];
        if (l > r) {
            A[i] = l;
            A[i - 1] = r;
            cnt++;
        }
    }
    if (cnt > 0) {
        cnt = bubbleSort(A, N, cnt);
    }
    return acc + cnt;
}

int main() {
    int N;
    scanf("%d", &N);
    
    int A[N];
    for (int i = 0;i < N;i++) {
        scanf("%d", &A[i]);
    }
    
    int cnt = bubbleSort(A, N, 0);
    writeLine(A, N);
    printf("%d\n", cnt);
   
    return 0;
}

