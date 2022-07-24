#include <array>
#include <iostream>
#include <string>
#include <vector>

struct Node {
	int key;
	Node *left, *right;
};

constexpr size_t MAX_NODE = 1000;

int node_count = 0;
Node node_pool[MAX_NODE];

Node* new_node(int x) {
	node_pool[node_count].key = x;
	node_pool[node_count].left = nullptr;
	node_pool[node_count].right = nullptr;

	return &node_pool[node_count++];
}

class BinarySearchTree {
	Node* root;

public:
	BinarySearchTree() = default;

	void init() {
		root = nullptr;
		node_count = 0;
	}

	void insert(int x) {
		if (root == nullptr) {
			root = new_node(x);
			return;
		}

		for (Node* node = root; node->key != x;) {
			Node** child = x < node->key ? &node->left : &node->right;
			if (*child == nullptr) {
				*child = new_node(x);
				return;
			}
			node = *child;
		}
	}

	void remove(int x) {
		Node* parent = nullptr;
		Node* node = root; // 지우고자 하는 node

		while (node != nullptr && node->key != x) {
			parent = node;
			node = (x < node->key) ? node->left : node->right;
		}

        //원소가 이미 트리에 존재하지 않는 경우
		if (node == nullptr) return; 

        // 두 자식이 존재하지 않는 경우
		if (node->left == nullptr && node->right == nullptr) {
			if (parent == nullptr) root = nullptr;
			else ((node == parent->left) ? parent->left : parent->right) = nullptr;
			
		} else if (node->left == nullptr) {
			*node = *node->right;
		} else if (node->right == nullptr) {
			*node = *node->left;
		} else { // 두 자식 모두 존재하는 경우
			// find successor
			parent = node;

            //오른쪽 서브트리의 제일 작은 원소 찾기
			Node* successor = node->right;
			while (successor->left != nullptr) {
				parent = successor;
				successor = successor->left;
			}
			
            //successor는 기존 node를 대체
            node->key = successor->key;
            
            //parent는 successor의 기존 부모
			((successor == parent->left) ? parent->left : parent->right) = successor->right;
		}
	}

	bool find(int x) const {
		Node* node = root;
		while (node != nullptr) {
			if (node->key == x)
				return true;
			
			node = (x < node->key) ? node->left : node->right;
		}
		return false;
	}

	void traversal(int type) const {
		if (type == 0) {
			std::cout << "pre-order  ";
			pre_order();
		} else if (type == 1) {
			std::cout << "in-order  ";
			in_order();
		} else {
			std::cout << "post-order  ";
			post_order();
		}
		std::cout << '\n';
	}

private:
	void pre_order() const {
		std::vector< Node*> stk;
		stk.emplace_back(root);

		while (!stk.empty()) {
			const Node* node = stk.back();
			stk.pop_back();

			std::cout << node->key << ' ';

			if (node->right != nullptr) stk.emplace_back(node->right);
			if (node->left != nullptr) stk.emplace_back(node->left);
		}
		std::cout << '\n';
	}

	void in_order() const {
        std::vector< Node*> stk;
		stk.emplace_back(root);
        
        while(!stk.empty()){
			Node* node = stk.back();
            Node* parent;
            while(node -> left != nullptr){
                parent = node;
                node = node->left;
                parent->left = nullptr;
                stk.emplace_back(node);
            }

            stk.pop_back();
            std::cout << node->key << ' ';

            if (node->right != nullptr) stk.emplace_back(node->right);

        }
        std::cout << '\n';
        
	}

	void post_order() const {
		std::vector< Node*> stk;
		stk.emplace_back(root);

		while (!stk.empty()) {
			Node* node = stk.back();

            if (node -> right == nullptr && node->left == nullptr){
                std::cout << node->key << ' ';
                stk.pop_back();
            }

			if (node->right != nullptr) {
                stk.emplace_back(node->right);
                node -> right = nullptr;
            }
			if (node->left != nullptr) {
                stk.emplace_back(node->left);
                node -> left = nullptr;
            }

		}
		std::cout << '\n';

	}
};

int main() {
	BinarySearchTree tree {};
	// 0   : 초기화
	// 1 x : x 삽입
	// 2 x : x 삭제
	// 3 x : x 탐색
	// 4 t : 순회 (t: 0 전위, 1 중위, 2 후위)
	int cmd, x;
	for (;;) {
		std::cin >> cmd;
		switch (cmd) {
		case 0:
			tree.init();
			break;
		case 1:
			std::cin >> x;
			tree.insert(x);
			break;
		case 2:
			std::cin >> x;
			tree.remove(x);
			break;
		case 3:
			std::cin >> x;
			std::cout << (tree.find(x) ? "found" : "not found") << '\n';
			break;
		case 4:
			std::cin >> x;
			if (x < 0 || x > 2) return std::cout << "invalid traversal type\n", 0;
			tree.traversal(x);
			break;
		default:
			return std::cout << "invalid command\n", 0;
		}
	}
}