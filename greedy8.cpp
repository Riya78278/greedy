// Fractional Knapsack
#include <iostream>
using namespace std;

class Solution {
public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();

        // Step 1: Create a vector of pairs to store value and weight together
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({val[i], wt[i]});
        }

        // Step 2: Sort items by their value-to-weight ratio (descending)
        // ⚠️ Use double to prevent integer division
        sort(v.begin(), v.end(), [](auto &a, auto &b) {
            return (double)a.first / a.second > (double)b.first / b.second;
        });

        double totalVal = 0.0; // To store the total maximum value we can take

        // Step 3: Traverse sorted items and fill the knapsack
        for (int i = 0; i < n; i++) {
            int value = v[i].first;
            int weight = v[i].second;

            // Case 1: Item can fit completely in the remaining capacity
            if (weight <= capacity) {
                totalVal += value;       // Add full item value
                capacity -= weight;      // Reduce capacity
            }
            // Case 2: Item can't fit completely → take fractional part
            else {
                double ratio = (double)value / weight; // Value per unit weight
                totalVal += ratio * capacity;          // Take only fraction
                break;                                 // Knapsack is now full
            }
        }

        return totalVal; // Step 4: Return the maximum value obtained
    }
};