#include<bits/stdc++.h>
using namespace std;

class RandomizedCollection {
private:
    unordered_map<int, unordered_set<int>> mp;
    vector<int> arr;
    int syze;
public:
    RandomizedCollection() { syze = 0; }
    bool insert(int val) {
        bool ans = true;
        if (mp.find(val) != mp.end()) {
            ans = false;
        }
        arr.push_back(val);
        syze++;
        mp[val].insert(syze - 1);
        return ans;
    }

    bool remove(int val) {
        if (syze == 0) {
            return false;
        }
        if (mp.find(val) == mp.end()) {
            return false;
        }
        auto ElementWithIndex = mp[val].begin();
        int index = *ElementWithIndex;
        mp[val].erase(index);
        if (mp[val].size() == 0) {
            mp.erase(val);
        }
        if (index != syze - 1) {
            int lastElementInArray = arr[syze - 1];
            arr[index] = lastElementInArray;
            mp[lastElementInArray].erase(syze-1);
            syze--;
            arr.pop_back();
            mp[lastElementInArray].insert(index);
        } else {
            syze--;
            arr.pop_back();
        }
        return true;
    }

    int getRandom() {
        if (syze == 0) {
            return -1;
        }
        int index = rand() % syze;
        return arr[index];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */