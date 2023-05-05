#include <stdio.h>
#include <stdlib.h>

/*
	Node 구조체
*/
typedef struct Node
{
	int data;		// 노드에 저장된 데이터
	Node* next;		// 다음 노드 주소값
};

/*
	Linked List의 앞에 추가

	- 앞에다 추가하는 거지 처음에만 사용하는 건 아님!!
*/
Node* add_first(Node* head, int value) 
{
	Node* p = (Node*)malloc(sizeof(Node));		// p라는 동적 변수 생성

	p->data = value;	// p->data에 저장할 값(value) 넣기

	p->next = head;		// p->next를 head로 설정
	head = p;			// 이제부터 head(맨 앞)은 p


	return head;		// head 반환
}

/*
	Linked List의 뒤에 추가
*/
Node* add_last(Node* head, Node* pre, int value)
{
	Node* p = (Node*)malloc(sizeof(Node));		// p라는 동적 변수 생선

	p->data = value;
	p->next = pre->next;	// p->next를 pre->next로 설정
	pre->next = p;			// 이제부터 pre->next는 p임


	return head;	// head 반환
}

/*
	맨 앞 노드 삭제
*/
Node* del_first(Node* head)
{
	Node* remove;	// 삭제할 노드를 저장할 변수

	if (head == NULL)	// 만약 head가 이미 NULL 일 때 NULL 반환
	{
		return NULL;
	}

	remove = head;			// remove는 head
	head = remove->next;	// head는 remove->next (= 이제부터 head는 현재 지울 값의 다음 값. 저것들 다 포인터라 주소로 넘어감)

	free(remove);	// 동적메모리 없에기(= head 없에기)


	return head;	// head 반환
}

/*
	pre 다음 노드 삭제
*/
Node* del_next(Node* head, Node* pre)
{
	Node* remove;	// 삭제할 노드를 저장할 변수

	remove = pre->next;			// pre의 다음 노드를 삭제하기 위해 remove를 pre->next로 설정
	pre->next = remove->next;	// 삭제할 변수의 자리는 이제 삭제할 변수의 다음 녀석이 차지 (remove를 가리키던 걸 remove의 다음 것으로 바꿈)

	free(remove);		// 동적메모리(지울 노드) 없에기


	return head;	// head 반환
}

/*
	원하는 부분의 노드 주소 반환
*/
Node* search_node(Node* head, int loop)
{
	Node* p = head;

	for (int q = 0; q < loop; q++)
	{
		if (p != NULL)
		{
			p = p->next;
		}
		else
		{
			return NULL;
		}
	}


	return p;
}

/*
	연결리스트 출력
*/
void print_list(Node* head)
{
	for (Node* p = head; p != NULL; p = p->next)	// p의 값이 계속 그 다음 값이 되면서 다음 값이 없을 때까지(NULL) 반복
	{
		printf("%d -> ", p->data);
	}

	printf("NULL \n");
}

/*
	연결리스트에 데이터 추가
*/
Node* add_linkedlist(Node* head)
{
	printf("\n\n");

	printf("리스트의 앞에 데이터를 추가한다 -> (1) / 리스트의 뒤에 데이터를 추가한다 -> (2) \n> ");
	int input = 0, pre_data = 0, value = 0;
	scanf("%d", &input);

	if (input == 1)
	{

		printf("\n추가하고 싶은 데이터를 입력해주세요 \n> ");
		scanf("%d", &value);

		head = add_first(head, value);

		printf("\n");
	}
	else
	{

		printf("\n");
		print_list(head);
		printf("\n몇번째 데이터(0부터 시작)에 어떤 데이터를 넣을건지 입력해주세요 \n> ");
		scanf("%d %d", &pre_data, &value);

		Node* pre_node_num = search_node(head, pre_data);

		if (pre_node_num != NULL)
		{
			head = add_last(head, pre_node_num, value);

			printf("\n");
		}
		else
		{
			printf("\n그딴 거 없습니다..? \n");
		}
	}


	return head;
}

/*
	연결리스트에 데이터 삭제
*/
Node* del_linkedlist(Node* head)
{
	printf("\n\n");

	printf("리스트의 앞에 데이터를 삭제한다 -> (1) / 리스트의 뒤에 데이터를 삭제한다 -> (2) \n> ");
	int input = 0, pre_data = 0;
	scanf("%d", &input);

	if (input == 1)
	{
		head = del_first(head);

		printf("\n");
	}
	else
	{

		printf("\n");
		print_list(head);
		printf("\n몇번째 데이터(0부터 시작)의 다음 데이터를 삭제할 건가요? \n> ");
		scanf("%d", &pre_data);

		Node* pre_node_num = search_node(head, pre_data);

		if (pre_node_num != NULL)
		{
			head = del_next(head, pre_node_num);

			printf("\n");
		}
		else
		{
			printf("\n그딴 거 없습니다..? \n");
		}
	}


	return head;
}

int main()
{
	Node* head = NULL;

	while (1)
	{
		printf("\n데이터를 입력하실 건가요? (예 -> 1, 아니오 -> 0) \n> ");
		int input = 0;
		scanf("%d", &input);

		if (input == 1)
		{
			head = add_linkedlist(head);
		}
		else
		{
			break;
		}
	}
	while (1)
	{
		printf("\n데이터를 삭제하실 건가요? (예 -> 1, 아니오 -> 0) \n> ");
		int input = 0;
		scanf("%d", &input);

		if (input == 1)
		{
			head = del_linkedlist(head);
		}
		else
		{
			break;
		}
	}

	printf("\n\n\n");
	print_list(head);


	return 0;
}
