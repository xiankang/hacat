#include "test_knapsack.hpp"
#include "common\knapsack.hpp"
#include <iostream>



void TestKnapsack::run() {

	std::cout << "TestKnapsack" << std::endl;

	vector<int> weights = { 2,2,3,6,4,5,6,7,8,2,3,4,6 };
	vector<int> values = { 6,5,3,2,4,2,5,6,8,4,3,5,9 };
	vector<Item> items;
	for (int i = 0; i < weights.size(); ++i) {
		Item item;
		item.index = i;
		item.weight = weights[i];
		item.value = values[i];
		items.push_back(item);
	}

	vector<Item> result;
	std::cout << "max value: " << max_knapsack_value(items, items.size() - 1, 16, result) << std::endl;

	for (int i = 0; i < result.size(); ++i) {
		std::cout << result[i].index << std::endl;
	}
}

