#include <iostream>
#include <list>
#include <unordered_map>

using namesapce std;

class Node
{
public:
    string key;
    int value;
    Node(string key, int value)
    {
        this->key = key;
        this->value = value;
    }
};

class LRUcache
{
public:
    int capacity; // declares max capacity of cache memory
    list<Node> cache;
    unordered_map<string, list<Node>::iterator> mp; // here each key stores the address of linked list - >stl container address storage mechanism
    LRUcache(int capacity)
    {
        this->capacity = (capacity == 0) ? 1 : capacity; // this will ensure min capacity is one
    }

    void insert(string key, int value)
    {
        // 2 cases
        // if value is present, then update it ; else add new key value pair in cache and store its key and address in mp
        if (mp.count(key))
        {
            auto it : mp[key]; // cache address to key element
            it->value = value;
        }
        else
        {
            // check if cache has space to add new element
            if (cache.size() == capacity)
            {
                Node last = cache.back();
                mp.erase(last.key); // remove from haspmap as well
                cache.pop_back();   // then delete the least recent used element from the cache
            }
            Node node(key, value);
            cache.push_front(node);  // add to cache
            mp[key] = cache.begin(); // add new element to hashmap also
        }
    }

    int getValue(string key)
    {
        // if key exists in map -> which imples cache contains the key
        // return the value, and update its positon to front of the cache
        if (mp.count(key))
        {
            auto it : mp[key];
            int val = it->value;
            Node node = *it;
            cache.erase(it);         // removed the prev location
            cache.push_front(node);  //  added that node (containing complete data) it to the front of cache sequence
            mp[key] = cache.begin(); // update keys location in the map

            return val;
        }

        return -1; // if value is not present
    }

    string getRecentKey()
    {
        return cache.begin()->key;
    }
};

int main()
{

    return 0;
}