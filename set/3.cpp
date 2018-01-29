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
