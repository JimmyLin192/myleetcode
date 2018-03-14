class TrieNode {
public:
    bool active;
    vector<TrieNode*> nexts;
    TrieNode() {
        this->active = false;
        this->nexts = vector<TrieNode*>(26, NULL);
    }
};

class WordDictionary {
public:
    TrieNode* root;
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        int n = word.size();
        TrieNode* cur_node = root;
        for (int i = 0; i < n; i ++) {
            int cur_idx = word[i]-'a';
            if (cur_node->nexts[cur_idx] == NULL) {
                cur_node->nexts[cur_idx] = new TrieNode();
            }
            cur_node = cur_node->nexts[cur_idx];
        }
        cur_node->active = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchHelper(word, 0, root);
    }
    bool searchHelper(string& word, int index, TrieNode* cur_node) {
        int n = word.size();
        for (int i = index; i < n; i ++) {
            int cur_idx = word[i] - 'a';
            if (word[i] == '.') {
                for (int j = 0; j < 26; j ++) {
                    if (cur_node->nexts[j] != NULL) {
                        if (searchHelper(word, i+1, cur_node->nexts[j])) {
                            return true;
                        }
                    }
                }
                return false;
            } else if (cur_node->nexts[cur_idx] == NULL) {
                return false;
            } 
            cur_node = cur_node->nexts[cur_idx];
        }
        return cur_node->active;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */

