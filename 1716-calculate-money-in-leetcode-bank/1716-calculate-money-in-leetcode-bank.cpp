class Solution {
public:
    int totalMoney(int n) {
        int amnt = 0;
        int mon = 1;
        int weekday = 0;
        for (int i = 1; i<=n;i++){
            amnt+=mon+weekday;
            weekday++;
            if (weekday==7){
                weekday=0;
                mon++;
            }
        }
        return amnt;
    }
};