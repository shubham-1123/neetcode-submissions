class Solution {
public:
    string encode(vector<string>& strs) {
        string res;

        for (const string& s : strs) {
            int len = s.size();

            res += char('0' + len / 100);
            res += char('0' + (len / 10) % 10);
            res += char('0' + len % 10);

            res += s;
        }

        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;

        int i = 0;

        while (i < s.size()) {

            int len =
                (s[i] - '0') * 100 +
                (s[i + 1] - '0') * 10 +
                (s[i + 2] - '0');

            i += 3;

            res.push_back(s.substr(i, len));

            i += len;
        }

        return res;
    }
};

