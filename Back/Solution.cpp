#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<utility>
#include<queue>
#include "head.h"

using std::max;
using std::min;
using std::string;
using std::unordered_map;
using std::pair;
using std::queue;

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
int Solution::longestConsecutive(vector<int>& nums)
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
void  Solution::moveZeroes(vector<int>& nums)
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
int Solution::maxArea(vector<int>& height)
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
vector<vector<string>> Solution::groupAnagrams(vector<string>& strs) {
	unordered_map<string, vector<string>> Hashmap;
	const int wordnum = 26;

	for (const auto& str : strs) {
		int count[26] = { 0 };
		for (const char& c : str) {
			count[c - 'a']++;
		}
		string key = "";
		for (int t = 0; t < wordnum; t++) {
			key = key + std::to_string(count[t]) + "#";
		}
		Hashmap[key].push_back(str);
	}

	vector<vector<string>> ans;
	for (const auto& pair : Hashmap) {
		ans.push_back(pair.second);
	}
	return ans;
}
int Solution::trap(vector<int>& height) {
	int n = height.size();
	if (n == 0) return 0;
	vector<int> left_max(n, 0), right_max(n, 0);
	int ans = 0;

	left_max[0] = height[0];
	for (int t = 1; t < n; t++) left_max[t] = max(left_max[t - 1], height[t]);

	right_max[n - 1] = height[n - 1];
	for (int t = (int)n - 2; t >= 0; t--) right_max[t] = max(right_max[t + 1], height[t]);

	for (int t = 0; t < n; t++) ans += min(left_max[t], right_max[t]) - height[t];
	return ans;
}
void Solution:: bfs(vector<vector<char>>& land, int x, int y) {
	int dx[4] = { 0, 0, -1, 1 };
	int dy[4] = { -1, 1, 0, 0 };
	queue<pair<int, int>> bfs_queue;

	bfs_queue.push({ x, y });
	land[x][y] = '0'; // 沉岛起点

	while (!bfs_queue.empty()) {
		auto axis = bfs_queue.front();
		bfs_queue.pop();

		for (int k = 0; k < 4; k++) {
			int x1 = dx[k] + axis.first;
			int y1 = dy[k] + axis.second;

			if ((x1 >= 0) && (x1 < land.size()) && (y1 >= 0) && (y1 < land[0].size()) && (land[x1][y1] == '1')) {
				land[x1][y1] = '0'; // 先沉岛
				bfs_queue.push({ x1, y1 }); // 再入队
			}
		}
	}
}
int Solution::numIslands(vector<vector<char>>& grid) 
{
	if (grid.empty()) return 0;
	int ans = 0;
	for (int x = 0; x < grid.size(); x++) 
	{
		for (int y = 0; y < grid[0].size(); y++) 
		{
			if (grid[x][y] == '1') 
			{
				bfs(grid, x, y);
				ans++;
			}
		}
	}
	return ans;
}
