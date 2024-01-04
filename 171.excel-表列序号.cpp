/*
 * @lc app=leetcode.cn id=171 lang=cpp
 *
 * [171] Excel 表列序号
 */

#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res=0;
        for(auto c:columnTitle){
            res = res * 26 + (c - 'A'+ 1);
        }
        return res;
    }
};
// @lc code=end

