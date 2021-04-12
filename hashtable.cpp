#include <vector>
#include <list>

using namespace std;

template<typename T>
class HashTable {
private:
    vector<list<T>> hash_table;
public:
    HashTable(int sz) {
        hash_table.reserve(sz);
        hash_table.resize(sz);
    }

    ~HashTable() {
    }

    bool insert(const T& t) {
        if (contains(t)) {
            return false;
        }
        int key = hash(t);
        list<T>& slot = hash_table[key];
        slot.push_front(t);
        return true;
    }

    bool remove(const T& t) {
        if (!contains(t)) {
            return false;
        }
        int key = hash(t);
        list<T>& slot = hash_table<key>;
        auto it = slot.find(slot.begin(), slot.end(), t);
        if (it == slot.end()) {
            return false;
        }
        slot.erase(it);
        return true;
    }

    bool contains(const T& t) {
        int key = hash(t);
        list<T>& slot = hash_table[key];
        auto it = slot.find(slot.begin(), slot.end(), t);
        if (it != slot.end()) {
            return true;
        }
        return false;
    }

private:
    int hash(const T& t) {
        return t % 33;
    }
};
