#include "longest_substring.h"
#include <string.h>

int lengthOfLongestSubstring(const char *s) {
    int seen[256] = {0};   // ASCII
    int left = 0, right = 0;
    int maxLen = 0;
    int n = strlen(s);

    while (right < n) {
        if (seen[(unsigned char)s[right]] == 0) {
            seen[(unsigned char)s[right]] = 1;
            int currentLen = right - left + 1;
            if (currentLen > maxLen)
                maxLen = currentLen;
            right++;
        } else {
            seen[(unsigned char)s[left]] = 0;
            left++;
        }
    }
    return maxLen;
}