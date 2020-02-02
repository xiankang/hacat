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
		int data[] = { 1,2,3,4,5,8,10,6,7 };
		int length = sizeof(data) / sizeof(data[0]);
		red_black_tree<int> r_b_tree;

		for (int i = 0; i < length; ++i) {
			r_b_tree.insert(data[i]);
		}

		std::cout << "test red black tree" << std::endl;

		tranverse(r_b_tree);
		/*print_red_black_tree(r_b_tree);*/
	}

	template<class T>
	void tranverse(red_black_tree<T>& rb)
	{
		//center left right
		tranverse(rb.get_root());
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


