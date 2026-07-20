class Solution {
public:
    string convert(int digit, char one, char five, char ten) {
        string ans = "";
        if (digit == 9) {
            ans += one;
            ans += ten;
        }
        else if (digit >= 5) {
            ans += five;
            digit -= 5;
            while (digit--)
                ans += one;
        }
        else if (digit == 4) {
            ans += one;
            ans += five;
        }
        else {
            while (digit--)
                ans += one;
        }
        return ans;
    }
    string intToRoman(int num) {
        string ans = "";
        int thousands = num / 1000;
        while (thousands--)
            ans += 'M';
        ans += convert((num % 1000) / 100, 'C', 'D', 'M');
        ans += convert((num % 100) / 10, 'X', 'L', 'C');
        ans += convert(num % 10, 'I', 'V', 'X');

        return ans;
    }
};