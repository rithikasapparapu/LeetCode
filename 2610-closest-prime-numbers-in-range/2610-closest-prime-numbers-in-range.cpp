#include <vector>
#include <cmath>
#include <climits>

using namespace std;

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        int n = right - left + 1;
        vector<bool> marked(n, false); // marked[i] = true means (left + i) is NOT a prime
        
        // Mark numbers less than 2 as non-prime
        for (int i = 0; i < n; ++i) {
            int num = left + i;
            if (num < 2) {
                marked[i] = true;
            }
        }
        
        // Sieve of Eratosthenes up to sqrt(right)
        int sqrt_right = sqrt(right);
        vector<bool> sieve(sqrt_right + 1, true);
        sieve[0] = sieve[1] = false;
        for (int i = 2; i * i <= sqrt_right; ++i) {
            if (sieve[i]) {
                for (int j = i * i; j <= sqrt_right; j += i) {
                    sieve[j] = false;
                }
            }
        }
        
        // Mark multiples of primes in the range [left, right]
        for (int i = 2; i <= sqrt_right; ++i) {
            if (sieve[i]) {
                int start = max(i * i, ((left + i - 1) / i) * i);
                for (int j = start; j <= right; j += i) {
                    int idx = j - left;
                    if (idx >= 0 && idx < n) {
                        marked[idx] = true;
                    }
                }
            }
        }
        
        // Collect all primes in the range
        vector<int> primes;
        for (int i = 0; i < n; ++i) {
            if (!marked[i]) {
                primes.push_back(left + i);
            }
        }
        
        // Check for less than two primes
        if (primes.size() < 2) {
            return { -1, -1 };
        }
        
        // Find the pair with the smallest gap
        int min_gap = INT_MAX;
        vector<int> result = { primes[0], primes[1] };
        for (int i = 0; i < primes.size() - 1; ++i) {
            int gap = primes[i + 1] - primes[i];
            if (gap < min_gap) {
                min_gap = gap;
                result = { primes[i], primes[i + 1] };
            } else if (gap == min_gap && primes[i] < result[0]) {
                result = { primes[i], primes[i + 1] };
            }
        }
        
        return result;
    }
};
