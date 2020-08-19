class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        size_t nn = name.size(), tn = typed.size();
        int i = 0, j = 0;
        while (i <= nn && j < tn) {
            if (i < nn && name[i] == typed[j]) {
                i ++;
                j ++;
            } else if (i > 0 && typed[j] == name[i-1]) {
                j ++;
            } else break;
        }
        return i == nn && j == tn;
    }
};
