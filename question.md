원형 연결 리스트에서 노드를 탐색하는 연산에서
**return** 관련 질문

**********************
코드 102번째 줄

탐색을 해서 X값이 없다면 temp를 리턴을 하는데

원형 연결 리스트기 때문에 

각 노드의 링크들은 다음 주소를 가지고 있는데

어떻게 리턴 하는 건가요?

******************

`listNode *searchNode(linkedList_h *CL, char *x){`

    `listNode *temp;`

    `temp = CL -> head;      //CL의 head가 가지고 있는 주소값을 temp에 저장`

    `while(temp != NULL){    //노드가 있다는 거임`

        `if(strcmp(temp -> data, x) == 0) return temp;   //strcmp 는 문자열 비교 같으면 0 반환`

        `else temp = temp -> link;    // 같지 않다면 다음 노드로 넘어가기`

    `}`

    `return temp;    // 없으면 ???? NULL이 나올 수 있는 있을까요? 원형이면 계속 돌꺼 같은데요`
    
`}`