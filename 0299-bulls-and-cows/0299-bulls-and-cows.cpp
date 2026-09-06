class Solution {
public:
    string getHint(string secret, string guess) {

        int bulls = 0;
        int cows = 0;

        vector<int> freqSecret(10, 0);
        vector<int> freqGuess(10, 0);

        // Find bulls
        for(int i = 0; i < secret.length(); i++) {

            if(secret[i] == guess[i]) {
                bulls++;
            }
            else {
                freqSecret[secret[i] - '0']++;
                freqGuess[guess[i] - '0']++;
            }
        }

        // Find cows
        for(int i = 0; i < 10; i++) {
            cows += min(freqSecret[i], freqGuess[i]);
        }

        return to_string(bulls) + "A" + 
               to_string(cows) + "B";
    }
};