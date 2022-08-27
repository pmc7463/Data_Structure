#include <stdio.h>

typedef int element;

void sequentialSearch1(element a[], int n, int key) {
    int i = 0;
    printf ("\n %d를 검색하라 ! ->> ", key);
    while (i < n && a[i] != key) i++;
    if(i < n) printf("%d번째에 검색 성공 ! \n", i + 1);
    else printf("%d번째에 검색 실패 ! \n", i + 1);
}

void main() {
    element a[] = {8,30,1,9,11,19,2};
    int n = 7;

    sequentialSearch1(a, n, 9);
    sequentialSearch1(a, n, 6);
}