struct Node
{
   Node* link[26]; 
   bool flag; 
   bool containsKey(char ch)
   {
        return link[ch-'a'] != NULL; 
   }
   void putKey(char ch, Node* node)
   {
       link[ch-'a'] = node; 
   }
   Node* getKey(char ch)
   {
       return link[ch-'a']; 
   }
   void setEnd()
   {
       flag = true; 
   }
   bool isEnd()
   {
       return flag; 
   }
   
}; 
class Trie
{
    private : 
        Node* root; 
    public: 
        Trie()
        {
            root = new Node; 
        }
        void insert(string word)
        {
            Node* node = root; 
            for(int i = 0;i < word.length(); i++)
            {
                if(!node->containsKey(word[i]))
                    node->putKey(word[i], new Node()); 
                node = node->getKey(word[i]); 
            }
            node->setEnd(); 
        }
        bool search(string word)
        {
            Node* node = root; 
            for(int i = 0;i < word.length(); i++)
            {
                if(!node->containsKey(word[i]))
                    return false; 
                node = node->getKey(word[i]); 
            }
            if(!node->isEnd())
                return false;
            return true; 
        }
        bool startsWith(string word)
        {
            Node* node = root; 
            for(int i = 0;i < word.length(); i++)
            {
                if(!node->containsKey(word[i]))
                    return false; 
                node = node->getKey(word[i]); 
            }
            return true; 
        }
        
}; 
