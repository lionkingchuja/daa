#include <bits/stdc++.h>
using namespace std;

// Comparator to sort items by value-to-weight ratio in descending order
bool compareByValuePerWeight(pair<int, int>& a, pair<int, int>& b) {
    double ratioA = (double)a.first / (double)a.second;
    double ratioB = (double)b.first / (double)b.second;
    return ratioA > ratioB;
}

// Function to compute the maximum value that can be obtained in the knapsack
double fractionalKnapsack(int capacity, int values[], int weights[], int n) {
    // Vector to hold items as pairs of value and weight
    vector<pair<int, int>> items;
    for (int i = 0; i < n; i++) {
        items.push_back({values[i], weights[i]});
    }

    // Sorting items by value-to-weight ratio in descending order
    sort(items.begin(), items.end(), compareByValuePerWeight);

    // Variables to track the current weight in the knapsack and total value
    int currentWeight = 0;
    double totalValue = 0.0;

    // Loop through all items
    for (int i = 0; i < n; i++) {
        // If the item can fit completely in the knapsack
        if (currentWeight + items[i].second <= capacity) {
            currentWeight += items[i].second;
            totalValue += items[i].first;
        } 
        // If only a fraction of the item can be added
        else {
            int remainingCapacity = capacity - currentWeight;
            totalValue += (double)items[i].first / items[i].second * remainingCapacity;
            break;
        }
    }

    return totalValue;
}

int main() {
    // Number of items and capacity of the knapsack
    int n = 3, knapsackCapacity = 50;

    // Values and weights of the items
    int values[] = {100, 60, 120};
    int weights[] = {20, 10, 30};

    // Call the fractional knapsack function and get the result
    double maxValue = fractionalKnapsack(knapsackCapacity, values, weights, n);

    // Output the result with fixed precision
    cout << "The maximum value in the knapsack is: " << fixed << setprecision(2) << maxValue << endl;

    return 0;
}
