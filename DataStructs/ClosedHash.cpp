#include <iostream>
#include <vector>
#include <functional>
#include <algorithm> // Para std::random_shuffle
#include <random>    // Para std::default_random_engine

using namespace std;

// Estrutura para armazenar uma entrada na tabela hash
template<typename K, typename V>
struct Entry {
    K key;
    V value;
    bool isDeleted;

    Entry() : isDeleted(false) {}
    Entry(K k, V v, bool d) : key(k), value(v), isDeleted(d) {}

    Entry& operator=(const Entry& other) {
        if (this != &other) {
            key = other.key;
            value = other.value;
            isDeleted = other.isDeleted;
        }
        return *this;
    }
};

// Estrutura Dictionary
template<typename K, typename V>
struct Dictionary {
    int size; // tamanho da tabela hash
    int count; // número de elementos no dicionário
    vector<Entry<K, V>> H; // tabela hash como um array de Entry
    vector<int> Perm; // permutação de 1..m-1
    function<int(K)> h; // função de hash

    // Construtor
    Dictionary(int size, function<int(K)> hashFunc) : size(size), count(0), H(size), h(hashFunc) {
        // Inicializa a permutação de 1..m-1
        for (int i = 1; i < size; ++i) {
            Perm.push_back(i);
        }
        // Embaralha a permutação para garantir pseudo-random probing
        auto rng = default_random_engine {};
        shuffle(Perm.begin(), Perm.end(), rng);
    }

    // Função para buscar um elemento no dicionário
    V* find(K key) {
        int i = 0;
        int pos = h(key) % size;
        while (H[pos].key != key && !H[pos].isDeleted && i < size - 1) {
            pos = (h(key) + Perm[i]) % size;
            i++;
        }
        if (H[pos].key == key) {
            return &H[pos].value;
        } else {
            return nullptr;
        }
    }

    // Função para inserir um elemento no dicionário
    void insert(K key, V value) {
        if (count < size && find(key) == nullptr) {
            int i = 0;
            int pos = h(key) % size; // h é a função de hash
            while (H[pos].key != K() && !H[pos].isDeleted && i < size - 1) {
                pos = (h(key) + Perm[i]) % size;
                i++;
            }
            if (i < size - 1) {
                H[pos] = Entry<K, V>(key, value, false);
                count = count + 1;
            }
        }
    }
};

int main() {
    // Exemplo de uso do dicionário
    auto hashFunc = [](int key) { return key; }; // Função de hash simples
    Dictionary<int, string> dict(10, hashFunc);

    dict.insert(1, "one");
    dict.insert(2, "two");
    dict.insert(3, "three");
    dict.insert(32, "thirty-two");

    string* value = dict.find(2);
    if (value) {
        cout << "Value found: " << *value << endl;
    } else {
        cout << "Value not found" << endl;
    }

    value = dict.find(32);
    if (value) {
        cout << "Value found: " << *value << endl;
    } else {
        cout << "Value not found" << endl;
    }

    return 0;
}