// 3005. Count Elements With Maximum Frequency
#include <bits/stdc++.h>
using namespace std;

//Initial Solution
/* int maxFrequencyElements(vector<int> &nums)
{
    unordered_map<int, int> freq;
    int sum = 0;
    int max_freq = 0;
    for (auto i : nums)
    {
        freq[i]++;
        max_freq = max(max_freq, freq[i]);
    }
    for (auto i : freq)
    {
        if (i.second == max_freq)
        {
            sum += max_freq;
        }
    }
    return sum;
} */

//One Pass Solution
int maxFrequecyElements(vector<int> &nums)
{
    unordered_map<int, int> freq;
    int totalFrequency = 0;
    int maxFrequency = 0;

    for (int num : nums)
    {
        freq[num]++;
        int curr_frequency = freq[num];

        if (curr_frequency > maxFrequency)
        {
            maxFrequency = curr_frequency;
            totalFrequency = curr_frequency;
        }

        else if (curr_frequency == maxFrequency)
            totalFrequency += curr_frequency;
    }
    return totalFrequency;
}

int main()
{
    vector<int> nums;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        nums.emplace_back(num);
    }

    int ans = maxFrequecyElements(nums);
    cout << ans;
    return 0;
}