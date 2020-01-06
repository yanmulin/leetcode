// [+-]?[0-9]*
class Solution {
public:
    int myAtoi(string str) {
        int i, sign = 1, size = str.size();
        long unsigned n = 0;
        for (i=0;str[i]==' '&&i<size;i++);
        if (str[i] == '+') i++;
        else if (str[i] == '-') {
            sign = -1;
            i++;
        }
        while (i < size && isdigit(str[i])) {
            n *= 10;
            n += str[i] - '0';
            i ++;
            if (n == 1 << 31 && sign == -1) continue;
            if (n >> 31 > 0) return sign > 0 ? INT_MAX : INT_MIN;
        }
        return int(n) * sign;
    }
};
