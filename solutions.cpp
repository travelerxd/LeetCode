#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


struct ListNode{    //  2. add two numbers
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(NULL){}
};

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target); // 1. twoSum
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2); // 2. add two numbers
};


vector<int> Solution::twoSum(vector<int>& nums, int target){ // 1. twoSum
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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){  // 2. add two numbers
	ListNode* sumList = new ListNode(0);
	ListNode* p = sumList;
	int carry = 0;
	while(l1 != NULL || l2 != NULL || carry){
	int sum = (l1?l1->val:0) + (l2?l2->val:0) + carry;
	p->next = new ListNode(sum%10);
	carry = sum/10;
	l1 = l1?l1->next:l1;
	l2 = l2?l2->next:l2;
	p = p->next;
	}
	return sumList->next;
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

