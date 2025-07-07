#pragma once
#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <vector>
#include <functional>
#include <string>
#include <list>

template<typename K, typename V>
class HashTable {
private:
    class HashEntry {
    public:
        K key;
        V value;
        HashEntry(K k, V v) : key(k), value(v) {}
    };

    vector<list<HashEntry>> table;
    int capacity;

    int hashFunction(K key) {
        return hash<K>{}(key) % capacity;
    }

public:
    HashTable(int size = 101) : capacity(size) {
        table.resize(capacity);
    }

    void insert(K key, V value) {
        int index = hashFunction(key);
        for (auto& entry : table[index]) {
            if (entry.key == key) {
                entry.value = value;
                return;
            }
        }
        table[index].emplace_back(key, value);
    }

    V* get(K key) {
        int index = hashFunction(key);
        for (auto& entry : table[index]) {
            if (entry.key == key) {
                return &entry.value;
            }
        }
        return nullptr;
    }

    bool contains(K key) {
        return get(key) != nullptr;
    }
};

#endif
//M