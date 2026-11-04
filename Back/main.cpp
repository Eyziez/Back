#include<iostream>
#include<vector>
#include"head.h"


int main()
{
	Solution sol;
	std::vector<int> nums = { 1,2,3,4 };
	int target = 5;
	std::vector<int> ans = sol.twoSum(nums, target);
	std::cout << ans[0]<<"，"<<ans[1] << std::endl;
	return 0;
}