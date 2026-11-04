#pragma once
#include<iostream>
#include<vector>
#include<unordered_map>

using std::vector;

class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target);
    int longestConsecutive(vector<int>& nums);
    void moveZeroes(vector<int>& nums);
    int maxArea(vector<int>& height);

};