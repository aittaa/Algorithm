#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_NODE 10000

enum { ADD_HEAD = 1, ADD_TAIL, ADD_NUM, FIND, REMOVE, PRINT, PRINT_REVERSE, END = 99 };

extern void init();
extern void addNode2Head(int data);
extern void addNode2Tail(int data);
extern void addNode2Num(int data, int num);
extern int findNode(int data);
extern void removeNode(int data);
extern int getList(int output[MAX_NODE]);
extern int getReversedList(int output[MAX_NODE]);

static void run() {
	while (1) {
		int cmd, data, num, cnt, i = 0;
		int output[MAX_NODE] = { 0 };

		scanf("%d", &cmd);
		switch (cmd) {
		case ADD_HEAD: // 1
			scanf("%d", &data);
			addNode2Head(data);
			break;
		case ADD_TAIL: // 2
			scanf("%d", &data);
			addNode2Tail(data);
			break;
		case ADD_NUM: // 3
			scanf("%d %d", &data, &num);
			addNode2Num(data, num);
			break;
		case FIND: // 4
			scanf("%d", &data);
			num = findNode(data);
			printf("%d\n", num);
			break;
		case REMOVE: // 5
			scanf("%d", &data);
			removeNode(data);
			break;
		case PRINT: // 6
			cnt = getList(output);
			while (cnt--)
				printf("%d ", output[i++]);
			printf("\n");
			break;
		case PRINT_REVERSE: // 7
			cnt = getReversedList(output);
			while (cnt--)
				printf("%d ", output[i++]);
			printf("\n");
			break;
		case END:
			return;
		}
	}
}

int main(void) {
	//setbuf(stdout, NULL);
	//freopen("dll_input.txt", "r", stdin);

	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		printf("#%d\n", t);
		init();
		run();
		printf("\n");
	}

	return 0;
}



/////////////////

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node node_pool[MAX_NODE];
int node_count;
Node* head;
Node* tail;

Node* new_node(int data){
    node_pool[node_count].data = data;
    node_pool[node_count].prev = nullptr;
    node_pool[node_count].next = nullptr;
    
    return &node_pool[node_count++];
}

void init()
{
    head = new_node(-1);
    head -> prev = nullptr;
    head -> next = nullptr;
}

void addNode2Head(int data) 
{
    Node* newNode = new_node(data);
    Node* cur_node = head;

    newNode->next = head->next;
    head->next = newNode;

    newNode->prev = head;

    if(newNode->next != nullptr)
        newNode->next->prev = newNode;
        

}

void addNode2Tail(int data) 
{

    Node* cur_node = head;

    while(cur_node->next != nullptr)
        cur_node = cur_node->next;
    
    Node* newNode = new_node(data);

    newNode -> prev = cur_node;
    cur_node -> next = newNode;

}

void addNode2Num(int data, int num) 
{
    Node* cur_node = head;
    Node* newNode = new_node(data);

// 1 2 3 4 5 6 7 
    for(int i = 1; i < num; ++i){
        cur_node = cur_node->next;
    }

    newNode->next = cur_node->next;
    newNode->prev = cur_node;
    cur_node->next = newNode;
    if(newNode -> next != nullptr)
        newNode->next->prev = newNode;
    // newNode->next->prev = newNode;

}

int findNode(int data) 
{
    Node* cur_node = head->next;

    int i = 1;

    for(; data != cur_node->data; ++i){
        cur_node = cur_node->next;
    }

    return i;
}

void removeNode(int data) 
{
    Node* cur_node = head->next;

    while(cur_node != nullptr && data != cur_node->data)
        cur_node = cur_node->next;
    
    if(cur_node != nullptr){
        cur_node->prev->next = cur_node->next;

        if(cur_node->next != nullptr)
            cur_node->next->prev = cur_node->prev;
    }

}

int getList(int output[MAX_NODE]) 
{
    Node* cur_node = head;

    int i;
    for(i = 0; cur_node -> next != nullptr; ++i){
        cur_node = cur_node->next;
        output[i] = cur_node->data;
    }

    return i;
}

int getReversedList(int output[MAX_NODE]) 
{
    Node* cur_node = head;

    while(cur_node->next != nullptr)
        cur_node = cur_node->next;
    

    int i = 0;
    for(; cur_node -> prev != nullptr; ++i){
        output[i] = cur_node->data;
        cur_node = cur_node->prev;

    }

    return i;
}