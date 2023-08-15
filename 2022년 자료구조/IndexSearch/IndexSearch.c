#include <stdio.h>
#define INDEX_SIZE 3        // 인덱스 테이블의 크기를 3으로 정의
typedef int element;

// 인덱스 테이블의 구조(index, key)를 정의
typedef struct {
    int index;
    element key;
} iTable;

iTable indexTable[INDEX_SIZE];  // 인덱스 테이블 indexTable 생성

// 배열 a의 begin 원소와 end 원소 사이에서 key를 순차 검색
void sequentialSearch2(element a[], int begin, int end, element key) {
    int i = begin;

    printf("\n %d를 검색하라 ! ->> ", key);
    while (i < end && a[i] < key) i++;

    if (a[i] == key) printf("%d번째에 검색 성공 ! \n", (i - begin) + 1);
    else printf("%d 번째에 검색 실패 !\n", (i - begin) + 1);
}

//배열 a에 대한 인덱스 테이블 만들기
void makeIndexTable(element a[], int size) {
    int i, n;
    n = size / INDEX_SIZE;      //인덱스 테이블에 들어가는 뱌열 원소의 간격 계산
    if (size % INDEX_SIZE > 0) n = n + 1;
    for (i = 0; i < INDEX_SIZE; i++) {   //인덱스 테이블의 채우기
        indexTable[i].index = i * n;
        indexTable[i].key = a[i * n];
    }
} 

//색인 순차 검색
void indexSearch(element a[], int n, element key) {
    int i, begin, end;
    if (key < a[0] || key > a[n - 1])
        printf("\n 찾는 키가 없습니다. 검색 실패 ! \n");

    // 인덱스 테이블을 검색하여 검색 범위 결정
    for (i = 0; i < INDEX_SIZE; i++) 
        if((indexTable[i].key <= key) && (indexTable[i + 1].key > key)) {
            begin = indexTable[i].index;
            end = indexTable[i + 1].index;
            break;
        }
    if(i == INDEX_SIZE) {
        begin = indexTable[i - 1].index;
        end = n;
    }

    sequentialSearch2(a,begin,end,key); //검색 범위에 대한 순차 검색 수행
}

void main() {
    element a[] = {1,2,8,9,11,19,29};
    int n = 7;
    printf("\n\t << 색인 순차 검색 >>\n");
    makeIndexTable(a,n);
    indexSearch(a,n,9);
    indexSearch(a,n,6);
}