class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        long long reversed = 0; // x ka ulta value store kr rha
        long long temp = x;     //bina badle dursa value store kr rha

        while (temp != 0)   // loop tab tak chalega tab tak  temp 0 na ho jaye
        {
            int p = temp % 10;  // p store krega temp ka last value
            reversed = reversed * 10 + p;  // reverse krne ke liye 10 se guna and  p ko jodna hoga
            temp /= 10;// 10 se divide krke last value kon fir se remove kr dena hai fir agla loop chalega same
        }

        return (reversed == x); // agar x ka vlaue same aa gaya to return krega true nhi hua to false
    }
};
