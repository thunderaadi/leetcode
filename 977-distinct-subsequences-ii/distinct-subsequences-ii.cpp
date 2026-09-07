class Solution {
public:
    const int mod = 1e9 + 7;

    int foo(int i, string &s, vector<int> &dp, vector<int> &last)
    {
        if(i < 0)
            return 1;

        if(dp[i] != -1)
            return dp[i];

        int c = s[i] - 'a';

        long long ans = 2LL * foo(i - 1, s, dp, last);

        if(last[c] != -1 && last[c] < i)
        {
            ans -= foo(last[c] - 1, s, dp, last);
        }

        ans %= mod;
        if(ans < 0)
            ans += mod;

        return dp[i] = ans;
    }

    int distinctSubseqII(string s)
    {
        int n = s.size();

        vector<int> dp(n, -1);
        vector<int> last(26, -1);

        for(int i = 0; i < n; i++)
        {
            if(last[s[i] - 'a'] != -1)
                continue;

            last[s[i] - 'a'] = i;
        }

        vector<int> prev(n, -1);
        vector<int> pos(26, -1);

        for(int i = 0; i < n; i++)
        {
            prev[i] = pos[s[i] - 'a'];
            pos[s[i] - 'a'] = i;
        }

        function<int(int)> solve = [&](int i) -> int
        {
            if(i < 0)
                return 1;

            if(dp[i] != -1)
                return dp[i];

            long long ans = 2LL * solve(i - 1);

            if(prev[i] != -1)
                ans -= solve(prev[i] - 1);

            ans %= mod;
            if(ans < 0)
                ans += mod;

            return dp[i] = ans;
        };

        return (solve(n - 1) - 1 + mod) % mod;
    }
};