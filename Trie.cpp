#include<bits/stdc++.h>

struct Node {
    // Basically links size is 26 but it may change according the problem.
    Node* links[26];
    bool flag = false;

    // It find the character is present in Trie or not.
    bool isContainKey(char ch){
        return (links[ch - 'a'] != nullptr); // or NULL
    }

    // It insert the character which is not present in the Trie.
    void putKey(char ch, Node* node){
        links[ch - 'a'] = node;
    }

    // This return the next Trie node.
    Node* getKey(char ch){
        return links[ch - 'a'];
    }

    // It set the flag when the word is end.
    void setEnd(){
        flag = true;
    }

    // This return if the word is end or not.
    bool isEnd(){
        return flag;
    }
};

// This is the Trie class
class Trie {

    Node* root;

    public:
        Trie() {
            root = new Node();
        }

        // Insert character into Trie
        void insert(string word){

            Node* node = root;

            for(int i = 0; i < word.length(); i++){

                if(!node->isContainKey(word[i]))
                    node->putKey(word[i], new Node());  // TC :- O(len)
                
                node = node->getKey(word[i]);
            }
            node->setEnd();
        }

        // Search if the string is present in the Trie or not
        bool search(string word){

            Node* node = root;

            for(int i = 0; i < word.length(); i++){

                if(!node->isContainKey(word[i]))
                    return false;
                
                node = node->getKey(word[i]);
            }

            return node->isEnd();
        }

        // Search if the prefix string is the part of this Trie or not
        bool StartsWith(string prefix){

            Node* node = root;

            for(int i = 0; i < prefix.length(); i++){

                if(!node->isContainKey(prefix[i]))
                    return false;

                node = node->getKey(prefix[i]);
            }

            return true;
        }

};