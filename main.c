#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* arr, int a, int b){
    int temp = *(arr + a);
    *(arr + a) = *(arr + b);
    *(arr + b) = temp;
}

void proclateDown(int* arr, int pos, int SIZE){
    int lchild = pos * 2;
    int rchild =  lchild + 1;
    int big = -1;
    if (lchild < SIZE)
        big = lchild;
    if (rchild < SIZE && (arr[rchild] - arr[lchild]) > 0)
        big = rchild;
    if (big != -1 && (arr[big] - arr[pos]) > 0){
        swap(arr, big, pos);
        proclateDown(arr, big, SIZE);
    }
}

void makeHeap(int* arr, int SIZE){
    size_t s = 0;
    if (SIZE % 2 == 0)
        s = (SIZE-1) / 2;
    s = SIZE / 2;
    for (int pos = s; pos >= 0; --pos){
        proclateDown(arr, pos, SIZE);
    }
}

void heapSort(int* arr, int s){
    while (s > 1){
        makeHeap(arr, s);
        swap(arr, 0, s - 1);
        --s;
    }
}

int main()
{
    int SIZE = 10000;
    srand(time(NULL));
    int* arr = (int*)calloc(SIZE, sizeof(int));
    for (int i = 0; i < SIZE; ++i)
        *(arr+i) = rand() % 100;
    for (int i = 0; i < SIZE; ++i)
        printf("%i ", *(arr+i));
    printf("\n");
    heapSort(arr, SIZE);
    for (int i = 0; i < SIZE; ++i)
        printf("%i ", *(arr+i));
    free(arr);
    return 0;
}
