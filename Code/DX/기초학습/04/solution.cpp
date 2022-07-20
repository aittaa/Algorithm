#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_NODE 10000

enum { ADD_HEAD = 1, ADD_TAIL, ADD_NUM, REMOVE, PRINT, END = 99 };

void init();
void addNode2Head(int data);
void addNode2Tail(int data);
void addNode2Num(int data, int num);
void removeNode(int data);
int getList(int output[MAX_NODE]);

static void run() {
	while (1) {
		int cmd, data, num, cnt, i;
		int output[MAX_NODE] = { 0 };

		scanf("%d", &cmd);
		switch (cmd) {
		case ADD_HEAD:
			scanf("%d", &data);
			addNode2Head(data);
			break;
		case ADD_TAIL:
			scanf("%d", &data);
			addNode2Tail(data);
			break;
		case ADD_NUM:
			scanf("%d %d", &data, &num);
			addNode2Num(data, num);
			break;
		case REMOVE:
			scanf("%d", &data);
			removeNode(data);
			break;
		case PRINT:
			cnt = getList(output);
			i = 0;
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
	// setbuf(stdout, NULL);
	// freopen("sll_input.txt", "r", stdin);

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

///////////

#define MAX_NODE 10000

struct Node {
	int data;
	Node* next;
};

Node node[MAX_NODE];
int nodeCnt;
Node* head;

Node* getNode(int data) {
	node[nodeCnt].data = data;
	node[nodeCnt].next = nullptr;
	return &node[nodeCnt++];
}

void init()
{
    head = getNode(-1);
    head->next = nullptr;
}

void addNode2Head(int data) 
{
    Node* node = getNode(data);
    node->next = head->next;
    head->next = node;
}

void addNode2Tail(int data) 
{
    Node* cur_node = head;

    while(cur_node->next != nullptr)
        cur_node = cur_node->next;
    
    cur_node->next = getNode(data);

}

void addNode2Num(int data, int num) 
{
     Node* cur_node = head;

    for(int i = 1; i < num; i++){
        cur_node = cur_node->next;
    }

    Node* nNode = getNode(data);

    nNode->next = cur_node->next;
    cur_node->next = nNode;

}

void removeNode(int data) 
{
    Node* cur_node = head;
    while(cur_node->next != nullptr && cur_node->next->data != data)
        cur_node = cur_node->next;

    if(cur_node -> next != nullptr)
        cur_node->next = cur_node->next->next;
}

int getList(int output[MAX_NODE]) 
{
    Node* cur_node = head;

    int i;
    for(i = 0; cur_node->next != nullptr; ++i){
        cur_node = cur_node->next;
        output[i] = cur_node->data;
    }

    return i;
}