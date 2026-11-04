#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include "head.h"
using std::max;
using std::min;


vector<int> Solution::twoSum(vector<int>& nums, int target)
{
	//this is Solution 1;
	std::unordered_map<int, int> map;
	for (int i = 0;i < nums.size();i++)
	{
		int ans = target - nums[i];
		if (map.find(ans) != map.end())
		{
			return { map[ans],i };
		}
		map[nums[i]] = i;
	}
	return {  };
}
int longestConsecutive(vector<int>& nums) 
{
	int ans = 0;
	std::unordered_set<int> Hashset;
	for (const auto& num : nums)
		Hashset.insert(num);
	for (const auto& num : Hashset)
	{
		if (Hashset.find(num-1) !=Hashset.end())//如果你不是老大哥就走开
			continue;
		else//如果你是老大哥，我们来循环吧。
		{
			int local_max = 0;
			for (int t = num;Hashset.find(t)!=Hashset.end();t++)//狠狠往前走
				local_max++;
			if (ans < local_max)
				ans = local_max;
		}
	}
	return ans;
}
void moveZeroes(vector<int>& nums) 
{
	int zero_num = 0;
	for (int t = 0;t < nums.size();t++)
	{
		if (nums[t] != 0)
			nums[t - zero_num] = nums[t];
		else
			zero_num++;
	}
	const int zero_for_point = nums.size() - zero_num;
	for (int t = zero_for_point;t< nums.size();t++)//咱们循环这么多次就够了
	{
		nums[t] = 0;
	}
}
int maxArea(vector<int>& height) 
{
	auto area = [](int left, int right, int width) 
	{
		return min(left, right) * width;
	};
	int left = 0, right = height.size()-1;
	int ans = 0;
	while (left< right)
	{
		int area_current = area(height[left], height[right], right - left);
		ans = max(ans, area_current);
		if (height[left] < height[right])
			left++;
		else
			right--;
	}
	return ans;
}
