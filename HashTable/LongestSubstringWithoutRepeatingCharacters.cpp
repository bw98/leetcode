//Runtime: 46 ms
#include<set>
#include<algorithm>
using std::set;
using std::max;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> mySet;
        int res = 0, temp = 0;       
        int i = 0,j = 0;
        int n = s.size();
        while (j < s.size()) {
            if (mySet.find(s[j]) != mySet.end()) {
                mySet.erase(s[i]);
                ++i;
            }
            else {
                mySet.insert(s[j]);
                ++j;
            }
            temp = mySet.size();
            res =  max(res, temp);
        }
        mySet.clear();
        return res;
    }
};

//Runtime: 32 ms
#include<unordered_map>
using std::unordered_map;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> um;
        int res = 0, start = 0, temp;       
        int i;
        int n = s.size();
        if (n == 0) {
            return 0;
        }
        for (i = 0; i < n; ++i) {
            char ch = s[i];
            if ((um.find(ch) != um.end()) && (um[ch] >= start)) {
                start = um[ch] + 1;
                um[ch] = i;
            }
            else {
                um[ch] = i;
                temp = i - start + 1;
                if (res < temp) {
                    res = temp;
                }
            }
        }
        um.clear();
        return res;
    }
};
