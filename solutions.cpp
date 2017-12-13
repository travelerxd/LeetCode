#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target); // 1. twoSum
};


vector<int> Solution::twoSum(vector<int>& nums, int target){
	vector<int> indices;
	unordered_map<int, int> hashArray;
	for(int i = 0; i < nums.size(); i++)
	{
		if(hashArray.find(target - nums[i]) != hashArray.end())
		{
			indices.push_back(hashArray[target - nums[i]]);
			indices.push_back(i);
			return indices;
		}
		hashArray[nums[i]] = i;
	}
}


int main()
{
	cout << "hello, world!" << endl;
	vector<int> a;
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	int target = 6;

	Solution mySolution;
	vector<int> indices = mySolution.twoSum(a, target);
	for(auto x:indices)
		cout << x << endl; 
	return 0;
}

