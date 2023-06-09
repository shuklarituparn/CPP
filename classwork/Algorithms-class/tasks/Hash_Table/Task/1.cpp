#include <iostream>
#include <vector>

class HashMap
{
private:
    static const int kInitialTableSize = 100;
    static const float kLoadFactorThreshold;

    struct KeyValuePair
    {
        int key;
        int value;
        KeyValuePair *next;
        KeyValuePair(int k, int v) : key(k), value(v), next(nullptr) {}
    };

    std::vector<KeyValuePair *> table_;
    int numElements_;

    void ResizeTable()
    {
        int new_table_size = table_.size() * 2;
        std::vector<KeyValuePair *> new_table(new_table_size, nullptr);
        for (auto bucket : table_)
        {
            while (bucket != nullptr)
            {
                KeyValuePair *current = bucket;
                bucket = bucket->next;
                int new_index = Hash(current->key, new_table_size);
                current->next = new_table[new_index];
                new_table[new_index] = current;
            }
        }
        table_ = std::move(new_table);
    }

    int Hash(int key, int table_size) { return key % table_size; }

public:
    HashMap() : table_(kInitialTableSize, nullptr), numElements_(0) {}

    void Add(int key, int value)
    {
        if ((float)numElements_ / table_.size() > kLoadFactorThreshold)
        {
            ResizeTable();
        }
        int index = Hash(key, table_.size());
        KeyValuePair *new_pair = new KeyValuePair(key, value);
        new_pair->next = table_[index];
        table_[index] = new_pair;
        numElements_++;
    }

    void Remove(int key)
    {
        int index = Hash(key, table_.size());
        KeyValuePair *prev = nullptr;
        KeyValuePair *current = table_[index];
        while (current != nullptr)
        {
            if (current->key == key)
            {
                if (prev != nullptr)
                {
                    prev->next = current->next;
                }
                else
                {
                    table_[index] = current->next;
                }
                delete current;
                numElements_--;
                break;
            }
            prev = current;
            current = current->next;
        }
    }

    bool Contains(int key)
    {
        int index = Hash(key, table_.size());
        KeyValuePair *current = table_[index];
        while (current != nullptr)
        {
            if (current->key == key)
            {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    int Get(int key)
    {
        int index = Hash(key, table_.size());
        KeyValuePair *current = table_[index];
        while (current != nullptr)
        {
            if (current->key == key)
            {
                return current->value;
            }
            current = current->next;
        }
        return -1; // Return default value if key not found
    }
};

const float HashMap::kLoadFactorThreshold = 0.75f;

int main()
{
    HashMap map;

    int queries;
    std::cin >> queries;

    while (queries != 0)
    {
        char operation;
        int key, value;
        std::cin >> operation >> key;

        if (operation == '+')
        {
            std::cin >> value;
            map.Add(key, value);
        }
        else if (operation == '-')
        {
            map.Remove(key);
        }
        else if (operation == '?')
        {
            std::cout << (map.Contains(key) ? "YES" : "NO") << "\n";
        }

        queries--;
    }

    return 0;
}
