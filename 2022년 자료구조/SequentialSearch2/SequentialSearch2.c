#include <stdio.h>

typedef int element;

void sequentialSearch2(element a[], int n, element key) {
    int i = 0;
    printf("\n %d를 검색하라 ! ->> ", key);
    while (a[i] < key) i++;
    if(a[i] == key) printf("%d 번째에 검색 성공 !\n", i + 1);
    else printf("%d 번째에 검색 실패 !\n", i + 1);
}

void main() {
    element a[] = {1,2,8,9,11,19,29};
    int n = 7;

    sequentialSearch2(a,n,9);
    sequentialSearch2(a,n,6);
}