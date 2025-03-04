class Solution {
public:
    bool btk(int n, int power, int temp) {
        if (temp == n) return true;
        if (temp > n || power > n) return false;

        if (btk(n, power * 3, temp + power)) return true;
        return btk(n, power * 3, temp);
    }

    bool checkPowersOfThree(int n) {
        return btk(n, 1, 0);
    }
};