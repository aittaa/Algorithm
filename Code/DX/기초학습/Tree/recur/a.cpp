
//초기화 
struct Node {
	int key;
	Node *left, *right;
};

// 정적 할당 방식
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
	}
	
    //삽입 : O(height)
	void insert(int x) {
		root = insert_rec(root, x);
	}
	
    //삭제 : O(height)
	void remove(int x) {
		root = remove_rec(root, x);
	}
	
    //탐색 : O(height)
	bool find(int x) const {
		Node* node = root;
		while (node != nullptr) {
			if (node->key == x) {
				return true;
			}
			node = x < node->key ? node->left : node->right;
		}
		return false;
	}


	void traversal(int type) const {
		static constexpr std::array< const char*, 3> traversal_types = {"pre", "in", "post"};
		std::cout << traversal_types[type] << "-order  ";
		traversal_rec(root, type);
		std::cout << '\n';
	}

private:
	Node* insert_rec(Node* node, int x) {
		if (node == nullptr) {
			return new_node(x);
		}

		if (x < node->key)
			node->left = insert_rec(node->left, x);
		else if (x > node->key)
			node->right = insert_rec(node->right, x);
		// x == node->key인 경우는 아무것도 안하고 그냥 리턴. (BST는 중복 비허용)

		return node;
	}	

	Node* remove_rec(Node* node, int x) {
		if (node == nullptr) {
			return node;
		}

		if (x < node->key)
			node->left = remove_rec(node->left, x);
		else if (x > node->key)
			node->right = remove_rec(node->right, x);
		else {
			if (node->left == nullptr) {    //한 쪽 자식이 없는 경우 node의 위치에 반대쪽 자식을 두도록 한다.
				return node->right;
			} else if (node->right == nullptr) {
				return node->left;
			}
			// 자식이 둘 다 있는 경우 오른쪽 서브트리의 제일 작은 값을 node로
			const int temp = find_min_key(node->right);
			node->key = temp;
			node->right = remove_rec(node->right, temp);
		}

		return node;
	}

	int find_min_key(Node* node) const {
		while (node->left != nullptr) {
			node = node->left;
		}
		return node->key;
	}

	void traversal_rec(Node* node, int type) const {
		if (node == nullptr) return;
		if (type == 0) std::cout << node->key << ' ';
		traversal_rec(node->left, type);
		if (type == 1) std::cout << node->key << ' ';
		traversal_rec(node->right, type);
		if (type == 2) std::cout << node->key << ' ';
	}
};