#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target); // 1. twoSum
};


vector<int> Solution::twoSum(vector<int>& nums, int target){
	vector<int> result;
	unordered_map<int, int> myHash;
	for(int i = 0; i < nums.size(); i++)
	{
		int myTarget = target - nums[i];
		if(myHash.find(myTarget) != myHash.end())
		{
			result.push_back(myHash[myTarget]);
			result.push_back(i);
			return result;
		}
		myHash[nums[i]] = i;
	}
}


int main()
{
	cout << "hello, world!" << endl;
	return 0;
}

