#include <stdio.h>

int size;

void intsertionSort(int a[], int size) {
    int i, j, t, temp;
    printf("\n정렬할 원소 : ");
    for(t = 0; t < size; t++)   printf("%d ", a[t]);
    printf("\n <<< 삽입 정렬 수행 >>>\n");
    for(i = 0; i < size; i++) {
        temp = a[i];
        j = i;
        while ((j > 0) && (a[j - 1] > temp)) {
            a[j] = a[j-1];      // 삽입 자리 이후의 원소를 뒤로 이동
            j = j - 1;
        }
        a[j] = temp;            // 삽입 자리에 원소 저장
        printf("\n %d단계 : ", i);
        for (t = 0; t < size; t++)  printf("%3d ", a[t]);
    }
}

void main() {
    int list[8] = {69,10,30,2,16,8,31,22};
    size = 8;

    intsertionSort(list, size);
}