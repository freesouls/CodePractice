class Solution {
public:
    string getHint(string secret, string guess) {
        int bull = 0;
        vector<int> secret_cnts(10, 0);
        vector<int> guess_cnts(10, 0);

        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                bull++;
            }
            secret_cnts[secret[i] - '0']++;
            guess_cnts[guess[i] - '0']++;
        }

        int cow = 0;
        for (int i = 0; i < 10; i++) {
            cow += std::min(secret_cnts[i], guess_cnts[i]);
        }
        cow -= bull;

        std::stringstream ss;
        ss << bull << "A" << cow << "B";
        return ss.str();
    }
};
