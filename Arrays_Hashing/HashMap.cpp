// URL:
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;
class MyHashMap
{
private:
    vector<vector<pair<int, int>>> buckets;
    static int const base = 796;
    int hash(int key)
    {
        return key % base;
    }

public:
    MyHashMap()
    {
        buckets.resize(base);
    }

    void put(int key, int value)
    {
        int idx = hash(key);
        auto &bucket = buckets[idx];
        for (int i = 0; i < bucket.size(); i++)
        {
            if (bucket[i].first == key)
            {
                bucket[i].second = value;
                return;
            }
        }
        buckets[idx].push_back({key, value});
    }

    int get(int key)
    {
        int idx = hash(key);
        auto &bucket = buckets[idx];
        for (int i = 0; i < bucket.size(); i++)
        {
            if (bucket[i].first == key)
            {
                return bucket[i].second;
            }
        }
        return -1;
    }

    void remove(int key)
    {
        int idx = hash(key);
        auto &bucket = buckets[idx];
        for (int i = 0; i < bucket.size(); i++)
        {
            if (bucket[i].first == key)
            {
                bucket.erase(bucket.begin() + i);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
int main()
{

    return 0;
}