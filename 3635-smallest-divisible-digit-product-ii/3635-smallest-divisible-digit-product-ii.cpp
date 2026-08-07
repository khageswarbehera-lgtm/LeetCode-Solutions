#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string smallestNumber(string num, long long t) {
        // Step 1: Validate t and get the required counts of prime factors
        long long cnt2 = 0, cnt3 = 0, cnt5 = 0, cnt7 = 0;
        long long temp = t;
        while (temp % 2 == 0) { cnt2++; temp /= 2; }
        while (temp % 3 == 0) { cnt3++; temp /= 3; }
        while (temp % 5 == 0) { cnt5++; temp /= 5; }
        while (temp % 7 == 0) { cnt7++; temp /= 7; }
        
        // If t has other prime factors, we can never reach it with digits 1-9
        if (temp != 1) {
            return "-1";
        }
        
        int n = num.length();
        
        // Precompute the prefix cumulative counts of prime factors provided by num
        vector<long long> p2(n + 1, 0);
        vector<long long> p3(n + 1, 0);
        vector<long long> p5(n + 1, 0);
        vector<long long> p7(n + 1, 0);
        
        int first_zero = n;
        
        for (int i = 0; i < n; ++i) {
            if (num[i] == '0' && first_zero == n) {
                first_zero = i;
            }
            
            int d = num[i] - '0';
            long long c2 = 0, c3 = 0, c5 = 0, c7 = 0;
            if (d > 0) {
                int temp_d = d;
                while (temp_d % 2 == 0) { c2++; temp_d /= 2; }
                while (temp_d % 3 == 0) { c3++; temp_d /= 3; }
                while (temp_d % 5 == 0) { c5++; temp_d /= 5; }
                while (temp_d % 7 == 0) { c7++; temp_d /= 7; }
            }
            
            p2[i + 1] = p2[i] + c2;
            p3[i + 1] = p3[i] + c3;
            p5[i + 1] = p5[i] + c5;
            p7[i + 1] = p7[i] + c7;
        }
        
        // Helper to determine the minimum and lexicographically smallest digits
        auto get_factor_digits = [&](long long nd2, long long nd3, long long nd5, long long nd7) {
            long long c8 = nd2 / 3;
            long long r2 = nd2 % 3;
            
            long long c9 = nd3 / 2;
            long long r3 = nd3 % 2;
            
            long long c4 = r2 / 2;
            r2 = r2 % 2;
            
            long long c6 = 0;
            // Consolidate factors optimally
            if (r2 == 1 && r3 == 1) {
                c6 = 1; r2 = 0; r3 = 0;
            }
            if (r3 == 1 && c4 == 1) {
                c6 = 1; r2 = 1; r3 = 0; c4 = 0;
            }
            
            string res = "";
            if (r2) res += '2';
            if (r3) res += '3';
            if (c4) res += '4';
            res += string(nd5, '5');
            if (c6) res += '6';
            res += string(nd7, '7');
            res += string(c8, '8');
            res += string(c9, '9');
            
            // Since elements are appended in increasing order, it is inherently sorted
            return res;
        };

        // Step 2: Check if original string works natively
        if (first_zero == n) {
            if (p2[n] >= cnt2 && p3[n] >= cnt3 && p5[n] >= cnt5 && p7[n] >= cnt7) {
                return num;
            }
        }

        // Step 3: Try to find a valid replacement strictly maintaining the largest possible prefix
        for (int i = n - 1; i >= 0; --i) {
            if (i > first_zero) {
                continue;
            }
            
            int d = num[i] - '0';
            // Only test strictly greater digits for the replaced index
            for (int bigger = d + 1; bigger <= 9; ++bigger) {
                long long b2 = 0, b3 = 0, b5 = 0, b7 = 0;
                int temp_b = bigger;
                while (temp_b % 2 == 0) { b2++; temp_b /= 2; }
                while (temp_b % 3 == 0) { b3++; temp_b /= 3; }
                while (temp_b % 5 == 0) { b5++; temp_b /= 5; }
                while (temp_b % 7 == 0) { b7++; temp_b /= 7; }
                
                long long h2 = p2[i] + b2;
                long long h3 = p3[i] + b3;
                long long h5 = p5[i] + b5;
                long long h7 = p7[i] + b7;
                
                // Check what primes are still needed
                long long nd2 = max(0LL, cnt2 - h2);
                long long nd3 = max(0LL, cnt3 - h3);
                long long nd5 = max(0LL, cnt5 - h5);
                long long nd7 = max(0LL, cnt7 - h7);
                
                string req_digits = get_factor_digits(nd2, nd3, nd5, nd7);
                int space = n - 1 - i;
                
                // Fits perfectly, safely pad with 1s and append generated digits
                if (req_digits.length() <= space) {
                    int ones = space - req_digits.length();
                    string suffix = string(ones, '1') + req_digits;
                    return num.substr(0, i) + to_string(bigger) + suffix;
                }
            }
        }

        // Step 4: If no valid combination of the same length is found, make a longer string by one element 
        string req_digits = get_factor_digits(cnt2, cnt3, cnt5, cnt7);
        int space = max(n + 1, (int)req_digits.length());
        int ones = space - req_digits.length();
        return string(ones, '1') + req_digits;
    }
};