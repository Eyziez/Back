#include<iostream>
#include<vector>
#include"head.h"
using std::cout;
using std::endl;

int main()
{
	Solution sol;
	std::vector<int> nums = { 1,2,3,4 };
	int target = 5;
	vector<int> ans = sol.twoSum(nums, target);
	cout << ans[0]<<"，"<<ans[1] << endl;
	return 0;
}