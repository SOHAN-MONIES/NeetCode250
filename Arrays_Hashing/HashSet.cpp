// URL:
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;

class MyHashSet
{
private:
    static const int base = 76;
    vector<vector<int>> buckets;
    int hash(int key)
    {
        return key % base;
    }

public:
    MyHashSet()
    {
        buckets.resize(base);
    }
    void add(int key)
    {
        int idx = hash(key);
        for (auto x : buckets[idx])
        {
            if (x == key)
                return;
        }
        buckets[idx].push_back(key);
    }

    void remove(int key)
    {
        int idx = hash(key);
        auto &bucket = buckets[idx];
        for (int i = 0; i < bucket.size(); i++)
        {
            if (bucket[i] == key)
            {
                bucket.erase(bucket.begin() + i);
                return;
            }
        }
    }

    bool contains(int key)
    {
        int idx = hash(key);
        auto &bucket = buckets[idx];
        for (int i = 0; i < bucket.size(); i++)
        {
            if (bucket[i] == key)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    MyHashSet *obj = new MyHashSet();
    obj->add(2);
    cout << obj->contains(2);
    return 0;
}