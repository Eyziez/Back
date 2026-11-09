#pragma once
#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>

using std::vector;
using std::string;

class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target);
    int longestConsecutive(vector<int>& nums);
    void moveZeroes(vector<int>& nums);
    int maxArea(vector<int>& height);
    vector<vector<string>> groupAnagrams(vector<string>& strs);
    int trap(vector<int>& height);
    void bfs(vector<vector<char>>& land, int x, int y);
    int numIslands(vector<vector<char>>& grid);
    vector<int> topKFrequent(vector<int>& nums, int k);
    int findKthLargest(vector<int>& nums, int k);
};