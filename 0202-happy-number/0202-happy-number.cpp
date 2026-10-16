class Solution {
    private:
    int getNext(int n) {
        int sum = 0;

        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }

        return sum;
    }
public:
    bool isHappy(int n) {
        int slow = getNext(n);
        int fast = getNext(getNext(n));

        while (slow != fast) {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }

        return slow == 1;
    }
};