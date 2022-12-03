#include "HashMap.h"

// hash function


// hash map getters
bool find(const float key1, const float key2, Restaurant R){
    float hashCode = hashFunction(key);

};

// hash map setters
void insert(const float key1, const float key2, const Restuarant R){
 
/*
        unsigned long hashValue = hashFunc(key);
        HashNode<K, V> *prev = NULL;
        HashNode<K, V> *entry = table[hashValue];

        while (entry != NULL && entry->getKey() != key) {
            prev = entry;
            entry = entry->getNext();
        }

        if (entry == NULL) {
            entry = new HashNode<K, V>(key, value);
            if (prev == NULL) {
                // insert as first bucket
                table[hashValue] = entry;
            } else {
                prev->setNext(entry);
            }
        } else {
            // just update the value
            entry->setValue(value);
        }
*/
    float hashCode = hashFunction(float key1, float key2);
    node(hashCode, R) *Prev = NULL;
    node(K,V) *entry = table[hashCode];

    
};
void removeNode(const float key1, const float key2){
 
 /*
        unsigned long hashValue = hashFunc(key);
        HashNode<K, V> *prev = NULL;
        HashNode<K, V> *entry = table[hashValue];

        while (entry != NULL && entry->getKey() != key) {
            prev = entry;
            entry = entry->getNext();
        }

        if (entry == NULL) {
            // key not found
            return;
        }
        else {
            if (prev == NULL) {
                // remove first bucket of the list
                table[hashValue] = entry->getNext();
            } else {
                prev->setNext(entry->getNext());
            }
            delete entry;
        }
 */
};

// hash map constructors
HashMap(){
    table = new node<K,V> *[TABLE_SIZE]();
};

// hash map destructors
~HashMap(){

 // Change This Up
 /*
        // destroy all buckets one by one
        for (int i = 0; i < TABLE_SIZE; ++i) {
            HashNode<K, V> *entry = table[i];
            while (entry != NULL) {
                HashNode<K, V> *prev = entry;
                entry = entry->getNext();
                delete prev;
            }
            table[i] = NULL;
        }
        // destroy the hash table
        delete [] table;
 */
};

// node getters
float node::getHashCode(){
    return hashCode;
};
Restaurant node::getRestaurant(){
    return rstrnt;

};
Node *node::getNextNode(){
    return nextNode;
};

// node setters
void node::setRestaurant(Restuarant R){
    node::rstrnt = R;
};
void node::setHashCode(float code){
    hashCode = code;
};
void node::setNextNode(Node* N){
    nextNode = N;
};

// node constructors
node::node(const float K, const Restaurant R){
    setRestaurant(R);
    setHashCode(K);
};
