#include <vector>
#include <string>
#include <assert.h>
#include <algorithm>
using namespace std;
class Solution {
private:
    int find(string &s, int start, int len, char c) {
        // auto pstart = s.begin() + start, pend = s.begin() + start + len;
        // auto pfind = find(pstart, pend, c);
        // return pfind == pend ? -1 : pfind - pstart;
        for (int i=start;i<start+len;i++) {
            if (s[i] == c) return i;
        }
        return -1;
    }

public:
    int lengthOfLongestSubstring(string s) {
        #define MAX(a, b) ((a)>(b)?(a):(b))
        int size = s.size();
        if (size <= 1) return size;
        // int lens[2][size];
        // int startIndex = 0;

        // initialize
        // for (int i=0;i<size;i++) {
        //     lens[1][i] = 1;
        // }

        // for (int i=2;i<=size;i++) {
        //     int lowerRow = (i - 1) % 2;
        //     int upperRow = i % 2;
        //     for (int j=0;j<size-i+1;j++) {
        //         int idx = indice[j] + lens[lowerRow][j];
        //         if (idx >= indice[j + 1] && !haveRepeat(s, indice[j], lens[lowerRow][j], s[idx])) {
        //             lens[upperRow][j] = lens[lowerRow][j] + 1;
        //         } else if (lens[lowerRow][j] > lens[lowerRow][j+1]) {
        //             lens[upperRow][j] = lens[lowerRow][j];
        //         } else if (lens[lowerRow][j] <= lens[lowerRow][j+1]) {
        //             lens[upperRow][j] = lens[lowerRow][j+1];
        //             indice[j] = indice[j+1];
        //         } else {
        //             assert(false);
        //         }
        //     }
        // }

        int maxLength = 1;
        int startIndex = 0;
        int currentLength = 1;
        for (int i=1;i<size;i++) {
            int findIndex = find(s, startIndex, currentLength, s[i]);
            if (findIndex < 0) {
                currentLength ++;
                maxLength = MAX(currentLength, maxLength);
            } else {
                currentLength = i - findIndex;
                startIndex = findIndex + 1;
            }

        }

        return maxLength;
    }
};
