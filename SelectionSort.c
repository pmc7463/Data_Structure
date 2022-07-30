#include <stdio.h>

typedef int element;
int size;

//선택 정렬하는 연산
void SelectionSort(int a[], int size) {
    int i, j, t, min;
    element temp;
    printf("\n정렬할 원소 : ");
    for (t = 0; t < size; t++) printf("%d ",a[t]);       //정렬 전의 원소 출력
    printf("\n\n<<<<<<<< 선택 정렬 수행 >>>>>>>>\n");
    for (i = 0; i < size -1; i++) {     // 0 ~ 7까지 
        min = i;
        for ( j = i + 1; j < size; j++) { // j > 1 ~ 8 까지 
            if (a[j] < a[min]) min = j;     // 무슨 말인지 모르겠다 ㅡ,ㅡ
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
        printf("\n%d단계 : ", i + 1);
        for (t = 0; t < size; t++) printf("%3d",a[t]);
    }
}

void main(){
    element list[8] = {69, 10, 30, 2, 16, 8, 31, 22};  //정렬할 초기 원소 배열
    size = 8;
    SelectionSort(list,size);   // 선택 정렬 연산 호출
}