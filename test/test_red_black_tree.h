#include "common/red_black_tree.h"
#include "test_base.hpp"
#include "test_manager.hpp"
#include <cmath>
#include <vector>
#include <iomanip>

class test_red_black_tree : public TestBase
{
public:
	void run()
	{
		//
		const int length = 10000;
		int data[length];

		for (int i = 0; i < length; ++i)
		{
			data[i] = std::rand() % 10000;
		}

		red_black_tree<int> r_b_tree;

		for (int i = 0; i < length; ++i) {
			r_b_tree.insert(data[i]);
		}

		std::cout << "test red black tree" << std::endl;

		tranverse(r_b_tree);
		
		int* remove = data;
		for (int i = 0; i < length; ++i)
		{
			std::cout << "remove " << remove[i] << std::endl;
			r_b_tree.remove(remove[i]);
			//tranverse(r_b_tree);
		}
		//tranverse(r_b_tree);
		std::cout << "finish" << std::endl;
	}

	template<class T>
	void tranverse(red_black_tree<T>& rb)
	{
		//center left right
		std::cout << std::endl;
		tranverse(rb.get_root());
		std::cout << std::endl;
	}

	template<class T>
	void tranverse(red_black_tree_node<T>* tree)
	{
		if(tree != nullptr)
		{
			std::cout << " " << tree->value << (tree->is_black ? "b" : "r");
			tranverse(tree->left);
			tranverse(tree->right);
		}
	}
	
};


