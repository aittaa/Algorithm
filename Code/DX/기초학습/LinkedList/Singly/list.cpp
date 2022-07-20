#include <iostream>

struct Node{
    int data;
    Node* next;
};

//초기화
Node head;
void init(){
    head.next = nullptr;
}

// //동적 할당 방식
// Node* new_node(int data){
//     Node* node = new Node;

//     node->data = data;
//     node->next = nullptr;

//     return node;
// }

//정적 할당 방식
// 장점
//  1. 동적할당 오버헤드 x
//  2. 메모리 해제 필요 x
//  3. 캐시 효율 향상
constexpr size_t MAX_NODE = 10000;

int node_count;
Node node_pool[MAX_NODE];

Node* new_node(int data){
    node_pool[node_count].data = data;
    node_pool[node_count].next = nullptr;

    return &node_pool[node_count++];
}

class SinglyLinkedList{
    Node head;

public:
    SinglyLinkedList() = default;

    void init(){
        head.next = nullptr;
    }

    //맨 앞 삽입 : O(1)
    void insert(int x){
        Node* node = new_node(x);
        node->next = head.next;
        head.next = node;
    }

    //삭제 : O(N)
    void remove(int x){
        Node* cur_node = &head;
        while(cur_node->next != nullptr && cur_node->next->data != x)
            cur_node = cur_node->next;
        
        if(cur_node->next != nullptr)
            cur_node->next = cur_node->next->next;
        
    }

    //탐색 : O(N)
    Node* find(int x) const {
        Node* cur_node = head.next;
        while(cur_node != nullptr && cur_node->data != x)
            cur_node = cur_node->next;

        return cur_node;
    }


	void print() const {
		Node* ptr = head.next;
		std::cout << "[List]  ";
		while (ptr != nullptr) {
			std::cout << ptr->data;
			if (ptr->next != nullptr) {
				std::cout << " -> ";
			}
			ptr = ptr->next;
		}
		std::cout << '\n';
	}

};


int main() {
	SinglyLinkedList slist;
	// 0   : 초기화
	// 1 x : x 삽입
	// 2 x : x 삭제
	// 3 x : x 탐색
	int a, b;
	while (true) {
		std::cin >> a;
		switch (a) {
            case 0:
                slist.init();
                slist.print();
                break;
            case 1:
                std::cin >> b;
                slist.insert(b);
                slist.print();
                break;
            case 2:
                std::cin >> b;
                slist.remove(b);
                slist.print();
                break;
            case 3:
                std::cin >> b;
                std::cout << (slist.find(b) ? "found" : "not found") << '\n';
                break;
            default:
                return std::cout << "invalid input\n", 0;
		}
	}
}