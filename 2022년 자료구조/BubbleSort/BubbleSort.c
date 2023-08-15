#include <stdio.h>

typedef int element;
int size;

// 버블 정렬하는 연산
void bubbleSort(element a[], int size) {
    int i, j, t;
    element temp;
    printf("\n정렬할 원소 : ");
    for (t = 0; t < size; t++)  printf("%d ", a[t]);
    printf("\n <<< 버블 정렬 수행 >>>\n");
    for ( i = size -1; i > 0; i--){
        printf("\n %d단계 >>", size - i);
        for (j = 0; j <= i; j++){
            if (a[j-1] > a[j]) {        //j-1의 값이 j보다 크면 교체
                temp = a[j-1];
                a[j-1] = a[j];
                a[j] = temp;
            }
            printf("\n\t");
            for (t = 0; t < size; t++) printf("%3d  ",a[t]);
        }
    }
}

void main() {
    element list[8] = {69,10,30,2,16,8,31,22};
    size = 8;
    bubbleSort(list, size);
}