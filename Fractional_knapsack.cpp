#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int weight;
    int value;
    double ratio;

    Item(int w, int v) : weight(w), value(v) {
        ratio = static_cast<double>(v) / w; 
    }
};

bool compare(Item a, Item b) {
    return a.ratio > b.ratio; 
}

int main() {
    int n; 
    int W; 

    cout << "Enter the number of items and the capacity of the knapsack: ";
    cin >> n >> W;

    vector<Item> items;

    cout << "Enter weight and value for each item:\n";
    for (int i = 0; i < n; ++i) {
        int wi, vi;
        cin >> wi >> vi;
        items.emplace_back(wi, vi);
    }

    sort(items.begin(), items.end(), compare);

    double maxValue = 0.0;
    
    for (const Item& item : items) {
        if (W == 0) break;

        if (item.weight <= W) {
            maxValue += item.value; 
            W -= item.weight; 
        } else {
            maxValue += item.ratio * W; 
            W = 0; 
        }
    }

    cout << "Maximum value in the knapsack: " << maxValue << endl;

    return 0;
}
