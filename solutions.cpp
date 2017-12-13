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
	int lengthOfLongestSubstring(string s);     // 3. Longese Substring Without Repeating Characters
};




// 1. twoSum
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


// 2. add two numbers
ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2){  
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

// 3. Longest Substring Without Repeating characters. 
//    this is my solution. time cost is O(n2) and is a time costing solution
//    need other solution 
int Solution::lengthOfLongestSubstring(string s){ 
	int length = 0;
	if(s.size() == 0){
		return length;
	}
	unordered_set<char> substring;
	for(int i = 0; i < s.size(); i++){
		substring.insert(s[i]);
		for(int j = i + 1; j < s.size(); j++){
			if(substring.find(s[j]) != substring.end()){
				length = length > substring.size()?length:substring.size();
				substring.clear();
				break;
			}
			substring.insert(s[j]);
		}
		length = length > substring.size()?length:substring.size();
	}
	return length;
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

