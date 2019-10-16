#include <bits/stdc++.h>

using namespace std;

typedef struct trie_node
{
    unordered_map<int, trie_node *> children;
    bool end; //indicates whether it is the end of the string
    int freq;

    trie_node(bool x) : end(x)
    {
        children.clear();
        freq = 0;
    };

} Trie_Node;

void insert(Trie_Node *root, string s);
void insert_elegant(Trie_Node *root, string s);
void insert_recursive(Trie_Node *root, string s, int idx);
bool has_word(Trie_Node *root, string s);
bool has_word_recursive(Trie_Node *root, string s);
bool has_word_recursive_helper(Trie_Node *root, string s, int idx);
bool has_prefix(Trie_Node *root, string s);
bool has_prefix_recursive(Trie_Node *root, string s);
bool has_prefix_recursive_helper(Trie_Node *root, string s, int idx);
void delete_word(Trie_Node *root, string s);
bool delete_word_helper(Trie_Node *root, string s, int idx);

string shortest_unique_prefix(Trie_Node *root, string str)
{
    string ans = "";
    if (!root)
    {
        return ans;
    }
    Trie_Node *curr = root;
    int i;
    for (i = 0; i < str.size(); i++)
    {
        curr = curr->children[str[i]];
        if (!curr)
        {
            return ans;
        }
        else
        {
            ans += str[i];
            if (curr->freq == 1)
            {
                return ans;
            }
        }
    }

    return ans;
}

int main()
{
    Trie_Node *root = new Trie_Node(false);
    /*
    //insert_elegant(root,"abcdadfa403184938409183>>DFDFAF<><><>>*&&/%/%$#$#@$%$^^%^");
    //insert_elegant(root,"abcdadfa403184938409183>>DFDFAF<><><>>*&&%");
    //cout<<has_word(root,"bcdadfa403184938409183>>DFDFAF<><><>>*&&%")<<endl;
    //insert_elegant(root, "ab");
    
    //delete_word(root,"abcdadfa403184938409183>>DFDFAF<><><>>*&&%" );
    //cout<<(root!=NULL)<<endl;
    //cout<<has_prefix(root,"ab")<<endl;
    
    insert_elegant(root, "abcddfadfaaaaaaaaaaaaaaaaaaa343431413$%@$%@$%@$^@^%@^@^@$%@$%@$%@$%@$%@$^%&^*&(*@$%@$%$@^%&%");
    insert_elegant(root, "abc");
    delete_word(root,"abc");
    //cout<<has_prefix(root,"abc");
    cout<<has_word(root, "abcddfadfaaaaaaaaaaaaaaaaaaa343431413$%@$%@$%@$^@^%@^@^@$%@$%@$%@$%@$%@$^%&^*&(*@$%@$%$@^%&%");
    cout<<has_word(root, "abcddfadfaaaaaaaaaaaaaaaaaaa343431413$%@$%@$%@$^@^%@^@^@$%@$%@$%@$%@$%@$^%&^*&(*@$%@$%$@^%&");
    cout<<has_prefix(root, "abcddfadfaaaaaaaaaaaaaaaaaaa343431413$%@$%@$%@$^@^%@^@^@$%@$%@$%@$%@$%@$^%&^*&(*@$%@$%$@^%&");
    */
    /*
    insert_recursive(root, "abcddfadfaaaaaaaaaaaaaaaaaaa343431413$%@$%@$%@$^@^%@^@^@$%@$%@$%@$%@$%@$^%&^*&(*@$%@$%$@^%&%",0);
    cout<<has_word_recursive(root,"abcddfadfaaaaaaaaaaaaaaaaaaa343431413$%@$%@$%@$^@^%@^@^@$%@$%@$%@$%@$%@$^%&^*&(*@$%@$%$@^%&%")<<endl;
    delete_word(root,"abcddfadfaaaaaaaaaaaaaaaaaaa343431413$%@$%@$%@$^@^%@^@^@$%@$%@$%@$%@$%@$^%&^*&(*@$%@$%$@^%&%");
    cout<<has_prefix(root, "a")<<endl;
    cout<<has_prefix(root,"")<<endl;
*/

    insert_elegant(root, "zebra");
    insert_elegant(root, "dog");
    insert_elegant(root, "duck");
    insert_elegant(root, "dove");
    // insert_recursive(root, "xxy",0);
    //"bearcat", "bert"
    insert_elegant(root, "bearcat");
    insert_elegant(root, "bert");

    cout << shortest_unique_prefix(root, "zebra") << endl;
    cout << shortest_unique_prefix(root, "dog") << endl;
    cout << shortest_unique_prefix(root, "duck") << endl;
    cout<<shortest_unique_prefix(root, "dove")<<endl;

    cout << shortest_unique_prefix(root, "bearcat") << endl;
    cout << shortest_unique_prefix(root, "bert") << endl;

    return 0;
}

void insert(Trie_Node *root, string str)
{

    Trie_Node *curr = root;
    //unordered_map<int, Trie_Node*> curr_map ;

    for (int i = 0; i < str.size(); i++)
    {
        if (curr->children.find(str[i]) == curr->children.end())
        {
            Trie_Node *t = new Trie_Node(false);
            curr->children[str[i]] = t;
            //cout<<'x'<<endl;
        }
        curr = curr->children[str[i]];
    }
    curr->end = true;
}

void insert_elegant(Trie_Node *root, string str)
{
    Trie_Node *curr = root;

    for (auto x : str)
    {
        Trie_Node *node = curr->children[x];
        if (!node)
        {
            node = new Trie_Node(false);
            curr->children[x] = node;
        }

        //increase the frequency of the node visited
        curr->children[x]->freq++;

        curr = node;
    }

    curr->end = true;
}

bool has_prefix(Trie_Node *root, string str)
{
    Trie_Node *curr = root;
    unordered_map<int, Trie_Node *> curr_children; /* here the logic of current map works because the trie is already constructed
                                            and we are traversing the trie not changing it. But better is to traverse by 
                                            juchildrening to nodes then storing this info in a current map because copy of map will
                                            be done in this case.*/
    for (auto x : str)
    {
        curr_children = curr->children;
        if (curr_children.find(x) == curr_children.end())
        {
            return false;
        }
        curr = curr_children[x];
    }

    return true;
}

bool has_prefix_elegant(Trie_Node *root, string str)
{
    Trie_Node *curr = root;

    for (auto x : str)
    {
        Trie_Node *node = curr->children[x];
        if (!node)
        {
            return false;
        }
        curr = node; //jump to the child of the current node
    }

    return true;
}

bool has_word(Trie_Node *root, string str)
{
    Trie_Node *curr = root;

    for (auto x : str)
    {
        if (curr->children.find(x) == curr->children.end())
        {
            return false;
        }
        curr = curr->children[x]; //jump to the child of the current node
    }

    return curr->end == true;
}

void delete_word(Trie_Node *root, string str)
{
    delete_word_helper(root, str, 0);
}

bool delete_word_helper(Trie_Node *root, string str, int idx)
{
    //we have reached the final character in the string
    if (idx == str.size())
    {
        //if we reach the end of word then only delete if its end is true
        if (!root->end)
        {
            //cout<<'x'<<endl;
            return false;
        }
        root->end = false;
        return root->children.size() == 0;
    }

    int curr_ch = str[idx];
    Trie_Node *node = root->children[curr_ch];

    //before finishing the string traversal we have got a null node
    if (!node)
    {
        return false;
        //cout<<"y"<<endl;
    }

    //find out whether current node should be deleted by getting the result from the child node
    bool should_delete_curr = delete_word_helper(node, str, idx + 1);

    if (should_delete_curr)
    {
        //delete the children entry from the current node
        root->children.erase(curr_ch);
        //cout<<"x"<<endl;
        //if the current node doesn't have any child then we can delete current node also so send this info to the caller
        // that I am ready to be deleted
        return root->children.size() == 0;
    }

    return false;
}

void insert_recursive(Trie_Node *root, string str, int idx)
{
    if (idx == str.size())
    {
        root->end = true;
        return;
    }

    int curr_ch = str[idx];
    Trie_Node *node = root->children[curr_ch];
    if (!node)
    {
        node = new Trie_Node(false);
        root->children[curr_ch] = node;
    }

    insert_recursive(node, str, idx + 1);
}

bool has_word_recursive(Trie_Node *root, string str)
{
    return has_word_recursive_helper(root, str, 0);
}

bool has_prefix_recursive(Trie_Node *root, string str)
{
    return has_prefix_recursive_helper(root, str, 0);
}

bool has_word_recursive_helper(Trie_Node *root, string str, int idx)
{
    //reached the final character in the input string
    if (idx == str.size())
    {
        return root->end; // if the end of the current node is true then word is present else word is not present
    }

    int curr_ch = str[idx];
    Trie_Node *next = root->children[curr_ch];
    if (!next)
    {
        return false;
    }
    else
    {
        return has_word_recursive_helper(next, str, idx + 1);
    }
}

bool has_prefix_recursive_helper(Trie_Node *root, string str, int idx)
{
    //reached the final character in the input string
    if (idx == str.size())
    {
        return true; // if the end of the current node is true then word is present else word is not present
    }

    int curr_ch = str[idx];
    Trie_Node *next = root->children[curr_ch];
    if (!next)
    {
        return false;
    }
    else
    {
        return has_prefix_recursive_helper(next, str, idx + 1);
    }
}

/*

*********************Below is the code which has a bug****************************

void insert(Trie_Node *&root, string str){

    Trie_Node *curr= root;
    unordered_map<int, Trie_Node*> curr_map ;

    for(int i=0;i<str.size();i++){
        curr_map=curr->mp; *****************Here the curr_map will have a local copy and the new Trie_Node will be added
                           *****************in that map only which have the nodes not added in the tries                     
    
        if(curr_map.find(str[i])==curr_map.end()){
            Trie_Node *t= new Trie_Node(false);
            curr_map[str[i]]=t;
            
        }
        curr= curr_map[str[i]];
    }
       curr->end=true;
}
 

*/
