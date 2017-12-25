#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

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
	string longestPalindrome(string s); // 5. Longest Palindromic Substring
	string convert(string s, int numRows); // 6. ZigZag Conversion
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


// 5. Longest Palindromic Substring
string Solution::longestPalindrome(string s){
	if(s.empty())
            return "";
        if(s.size() == 1)
            return s;
        int min_start = 0, max_len = 1;
        for(int i = 0; i < s.size();){
            if(s.size() - i <= max_len / 2){  // 相当于把这个子串分成了两个部分，通过前后部分做比来判断是否是回文，i为中间的那个字符
                break;
            }
            int j = i, k = i;
            while(k < s.size() - 1 && s[k+1] == s[k]){ // 重复的字符
                ++k;
            }
            i = k + 1;
            while(k < s.size() - 1 && j > 0 && s[k+1] == s[j-1]){ // 从i这个位置开始向两边对比，若两边的值相等，那么再对比下一个位置的值
                ++k;
                --j;
            }
            int new_len = k - j + 1;
            if(new_len > max_len){
                max_len = new_len;
                min_start = j;
            }
        }
        return s.substr(min_start, max_len);
}

// 6. ZigZag Conversion
string Solution::convert(string s, int numRows){
if(s.empty())
            return "";
        if(numRows == 1)
            return s;
        string line;
        int base = (numRows - 2)*2 + 2;
        for(int i = 0; i < base; i++){
            int k = 0;
            while(k*base < s.size()){
                line.push_back(i + k*base);
                k++;
            }
        }
        return line;
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

