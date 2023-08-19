https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
28. Find the Index of the First Occurrence in a String
Given two strings needle and haystack, 
return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.


Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.
 

Constraints:

1 <= haystack.length, needle.length <= 104
haystack and needle consist of only lowercase English characters.



class Solution {
public:
    void buildLps(vector<int>&lps, string &needle) {
        int i = 1, j = 0;
        int n = needle.size();
        while (i < n) {
            if (needle[i] == needle[j]) {
                lps[i++] = ++j;
            } else {
                if (j) {
                    j = lps[j - 1];
                } else {
                    lps[i++] = 0;
                }
            }
        }
    }
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        if (m > n) {
            return -1;
        }
        vector<int> lps(n);
        buildLps(lps, needle);
        int i = 0, j = 0;

        while (i < n) {
            if (haystack[i] == needle[j]) {
                ++i;
                ++j;
            } else {
                if (j) {
                    j = lps[j - 1];
                } else {
                    ++i;
                }
            }
            if (j == m) {
                return i - j;
            }
        }

        return -1;
    }
};
