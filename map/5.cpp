#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {        
        int len = 0, maxlen = 0; 
        std::map<int, string, greater<int> > m; //use greater<> sort key instead of default less<>
        string substr = "";
        for (int i = 0; i < s.size(); ++i) {
            findPal(s, i-1, i+1, len, substr); // Palindrome is adjacent
            if (maxlen < len) {
                maxlen = len;
                m[len] = substr;
            }
            findPal(s, i, i+1, len, substr); // Palindrome is not adjacent
            if (maxlen < len) {
                maxlen = len;
                m[len] = substr;
            }
        }
        substr = m.begin()->second; //the first value means longestPalindrome
        return substr; 
    }
private:
    void findPal(const string& s, int left, int right, int& len, string& substring) {
        while (left >= 0 && right <= s.size()-1 && s[left] == s[right]) {
            left--;
            right++;
        }
        len = right -left -1; //subtract extra two lengths
        if (len < 1)
            return; //length of Palindrome must >= 1
        else 
            substring = s.substr(left+1, len);
    }
};
/*
int main(void) {
    string s = "a";
    Solution *sample = new Solution();
    string res = sample->longestPalindrome(s);
    cout << res << endl;
    return 0;
}
*/
