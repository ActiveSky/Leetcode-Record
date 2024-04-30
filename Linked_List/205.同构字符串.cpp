/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串

 */
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
   public:
    /**
     * transform string to number
     */
    string chars_to_nums(string s) {
        unordered_map<char, int> map;
        string res = "";
        for (auto c : s) {
            if (map.find(c) == map.end()) {
                map[c] = map.size();
            }
            res += to_string(map[c])+" ";
        }
        return res;
    }

   public:
    bool isIsomorphic(string s, string t) {
        return this->chars_to_nums(s) == this->chars_to_nums(t);
    }
};
// @lc code=end


int main() {
    Solution s;
    auto res_1=s.chars_to_nums("abcdefghijklmnopqrstuvwxyzva");
    auto res_2=s.chars_to_nums("abcdefghijklmnopqrstuvwxyzck");
    cout<<res_1<<endl<<res_2<<endl;
    return 0;
}
