#include <bits/stdc++.h>
using namespace std;

void countingSort(vector<int> &arr)
{
    int max1 = INT_MIN, min1 = INT_MAX;
    for (auto i : arr)
    {
        max1 = max(max1, i);
        min1 = min(min1, i);
    }
    int range = max1 - min1 + 1;
    // range required to set the size of count array
    vector<int> count(range), output(arr.size());
    for (int i = 0; i < arr.size(); i++)
        count[arr[i] - min1]++;
    for (int i = 1; i < count.size(); i++)
        count[i] += count[i - 1];
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        output[count[arr[i] - min1] - 1] = arr[i];
        count[arr[i] - min1]--;
    }
    for (int i = 0; i < arr.size(); i++)
        arr[i] = output[i];
}
int main()
{
    vector<int> arr = {4, 6, 0, 3, 8, 5, 1, 10};
    countingSort(arr);
    for (auto i : arr)
        cout << i << " ";
    return 0;
}