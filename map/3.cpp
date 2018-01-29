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
