#pragma once

//red_black_tree
template<class T>
struct red_black_tree_node
{
	T value;
	red_black_tree_node* parent;
	red_black_tree_node* left;
	red_black_tree_node* right;
	bool is_black;
	red_black_tree_node():parent(nullptr),left(nullptr),right(nullptr),is_black(false)
	{

	}
	red_black_tree_node(T value):value(value), parent(nullptr), left(nullptr), right(nullptr),is_black(false)
	{

	}
};

template<class T>
class red_black_tree
{
public:
	red_black_tree():root(nullptr),size(0)
	{

	}

	~red_black_tree()
	{
		clear();
	}

	void insert(T value)
	{
		//simple insert
		red_black_tree_node<T>* node = simple_insert(value);
		//fix
		fix_tree(node);
	}

	void remove(T value)
	{

	}
	bool has_value(T value)
	{
		red_black_tree_node<T>* tree = find_value(value);
		return tree != nullptr ? true : false;
	}
	red_black_tree_node<T>* find_value(T value)
	{
		red_black_tree_node<T>* tree = root;
		while (tree != nullptr)
		{
			if (tree->value == value)
				return tree;
			else if (value < tree->value) {
				tree = tree->left;
			}
			else {
				tree = tree->right;
			}
		}
		return nullptr;
	}
	void clear()
	{
		delete_tree(root);
		size = 0;
	}
	void delete_tree(red_black_tree_node<T>* tree)
	{
		if (tree != nullptr) {
			if(tree->left != nullptr)
				delete_tree(tree->left);
			if(tree->right != nullptr)
				delete_tree(tree->right);
			delete tree;
			tree = nullptr;
		}
	}

	red_black_tree_node<T>* get_root()
	{
		return root;
	}

	inline int get_size()
	{
		return size;
	}
private:
	//
	red_black_tree_node<T>* simple_insert(T value)
	{
		if (root == nullptr)
		{
			root = new red_black_tree_node<T>(value);
			++size;
			root->is_black = true;//root node default black
			return root;
		}
		else {
			return simple_insert(root, value);
		}
	}

	red_black_tree_node<T>* simple_insert(red_black_tree_node<T> *tree, T value)
	{
		if (value < tree->value) {
			//insert to left tree
			if (tree->left == nullptr) {
				tree->left = new red_black_tree_node<T>(value);
				tree->left->parent = tree;
				++size;
				return tree->left;
			}
			else {
				return simple_insert(tree->left, value);
			}
		}
		else if (value > tree->value) {
			//insert to right tree
			if (tree->right == nullptr) {
				tree->right = new red_black_tree_node<T>(value);
				tree->right->parent = tree;
				++size;
				return tree->right;
			}
			else {
				return simple_insert(tree->right, value);
			}
		}
		else {
			return tree;
		}

	}

	void left_rotation(red_black_tree_node<T>* node)
	{
		node->right->parent = node->parent;
		node->parent = node->right;	
		if(node->right->left != nullptr)
			node->right->left->parent = node;
		node->right = node->right->left;
		node->parent->left = node;
		if (node->parent->parent != nullptr)
		{
			if (node->parent->parent->left == node)
				node->parent->parent->left = node->parent;
			else if (node->parent->parent->right == node)
				node->parent->parent->right = node->parent;
		}
		if (root == node)
			root = node->parent;
	}
	//
	void right_rotation(red_black_tree_node<T>* node)
	{
		node->left->parent = node->parent;
		node->parent = node->left;
		if(node->left->right != nullptr)
			node->left->right->parent = node;
		node->left = node->left->right;
		node->parent->right = node;
		if (node->parent->parent != nullptr)
		{
			if (node->parent->parent->left == node)
				node->parent->parent->left = node->parent;
			else if (node->parent->parent->right == node)
				node->parent->parent->right = node->parent;
		}
		if (root == node)
			root = node->parent;
	}

	inline bool is_b_or_nil(red_black_tree_node<T>* node)
	{
		return node == nullptr || node->is_black;
	}
	inline bool is_r(red_black_tree_node<T>* node)
	{
		return node != nullptr && !node->is_black;
	}
	//
	void fix_tree(red_black_tree_node<T>* node)
	{
		if (is_b_or_nil(node))
			return;

		if (node->parent == nullptr)
		{
			//root
			node->is_black = true;
			root = node;
			return;
		}

		if (node->parent->parent == nullptr)
		{
			return;
		}

		if (node->parent == node->parent->parent->left)
		{
			if (is_r(node) && is_r(node->parent))
			{
				//case 1
				if (is_r(node->parent->parent->right))
				{
					//change color
					node->parent->is_black = true;
					node->parent->parent->right->is_black = true;
					node->parent->parent->is_black = false;
					fix_tree(node->parent->parent);
					return;
				}
				//case 2
				if (is_b_or_nil(node->parent->parent->right) && node == node->parent->right)
				{
					left_rotation(node->parent);
					node->parent->parent->is_black = false;
					node->parent->is_black = true;
					right_rotation(node->parent->parent);
					return;
				}
				//case 3
				if (is_b_or_nil(node->parent->parent->right) && node == node->parent->left)
				{
					node->parent->parent->is_black = false;
					node->parent->is_black = true;
					right_rotation(node->parent->parent);
					return;
				}
			}
		}
		else {
			if (is_r(node) && is_r(node->parent))
			{
				//case 1
				if (is_r(node->parent->parent->left))
				{
					//change color
					node->parent->is_black = true;
					node->parent->parent->left->is_black = true;
					node->parent->parent->is_black = false;
					fix_tree(node->parent->parent);
					return;
				}
				//case 2
				if (is_b_or_nil(node->parent->parent->left) && node == node->parent->left)
				{
					right_rotation(node->parent);
					node->parent->parent->is_black = false;
					node->parent->is_black = true;
					left_rotation(node->parent->parent);
					return;
				}
				//case 3
				if (is_b_or_nil(node->parent->parent->left) && node == node->parent->right)
				{
					//left rotation
					node->parent->parent->is_black = false;
					node->parent->is_black = true;
					left_rotation(node->parent->parent);
					return;
				}
			}
		}


	}
	//
	red_black_tree_node<T>* root;
	int size;
};
