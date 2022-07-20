
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
    Node* cur_node = head->next;
    while(cur_node->next != nullptr && cur_node->next->data != data)
        cur_node = cur_node.next;

    cur_node->next = cur_node->next->next;
}

int getList(int output[MAX_NODE]) 
{
    Node* cur_node = head;

    for(int i = 0; cur_node->next != nullptr, ++i){
        cur_node = cur_node->next;
        output[i] = cur_node->data;
    }

}