#pragma once
#include <stdlib.h>
#include <vector>
#include <unordered_map>

using namespace std;

//class Solution{
//public:
//    vector<int> twoSum(vector<int>& nums, int target){
//        unordered_map<int, int> sum_map;
//		for (int i = 0; i < nums.size(); ++i) {
//			int key = target - nums[i];
//			unordered_map<int, int>::iterator it = sum_map.find(key);
//			if (it != sum_map.end() && it->second != i) {
//				vector<int> result;
//				result.push_back(i);
//				result.push_back(it->second);
//				return result;
//			}
//			sum_map[key]=nums[i];
//		}
//		return vector<int>();
//    }
//};

struct Item
{
	int index;
	int weight;
	int value;
};

int max_knapsack_value(vector<Item>& items, int n, int opacity, vector<Item>& result) {

	if (n == 0) {
		Item& item = items[0];
		if (item.weight < opacity) {
			result.push_back(item);
			return item.value;
		}
		else {
			return 0;
		}
	}

	Item& item = items[n];
	if (item.weight > opacity) {
		return max_knapsack_value(items, n - 1, opacity, result);
	} else {
		vector<Item> temp;
		int result_1 = max_knapsack_value(items, n - 1, opacity, temp);
		int result_2 = max_knapsack_value(items, n - 1, opacity - item.weight, result) + item.value;
		if (result_2 > result_1) {
			result.push_back(item);
			return result_2;
		}
		else {
			result.swap(temp);
			return result_1;
		}
	}
}
