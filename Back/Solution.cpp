#include<iostream>
#include<vector>
#include<unordered_map>
#include "head.h"


std::vector<int> Solution::twoSum(std::vector<int>& nums, int target)
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

