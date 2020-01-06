class Solution {
public:
    string intToRoman(int num) {
        string roman = "";
        while (num >= 1000) {
            num -= 1000;
            roman += "M";
        }
        if (num >= 900) {
            roman += "CM";
            num -= 900;
        }
        if (num >= 500) {
            roman += "D";
            num -= 500;
        }
        if (num >= 400 ) {
            roman += "CD";
            num -= 400;
        }
        while (num >= 100) {
            num -= 100;
            roman += "C";
        }
        if (num >= 90) {
            roman += "XC";
            num -= 90;
        }
        if (num >= 50) {
            roman += "L";
            num -= 50;
        }
        if (num >= 40) {
            roman += "XL";
            num -= 40;
        }
        while (num >= 10) {
            num -= 10;
            roman += "X";
        }
        if (num == 9) {
            roman += "IX";
            num -= 9;
        }
        if (num >= 5) {
            roman += "V";
            num -= 5;
        }
        if (num == 4) {
            roman += "IV";
            num -= 4;
        }
        while (num > 0) {
            roman += "I";
            num -= 1;
        }
        return roman;
        
    }
};
