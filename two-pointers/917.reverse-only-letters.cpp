class Solution {
public:
    string reverseOnlyLetters(string S) {
        size_t n = S.size();
        int l = 0, r = n - 1;
        while (l < r) {
            if (!isalpha(S[l])) l ++;
            else if (!isalpha(S[r])) r --;
            else {
                swap(S[l++], S[r--]);
            }
        }
        return S;
    }
};
