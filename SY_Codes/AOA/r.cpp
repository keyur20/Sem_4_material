
#include <bits/stdc++.h> 
#define int long long 
using namespace std; 
map<char, string> codes; 
map<char, int> freq; 

 

struct Node 

{ 

    char data; 

    int freq; 

    Node *left; 

    Node *right; 

    Node(char data, int freq) 

    { 

        left = right = NULL; 

        this->data = data; 

        this->freq = freq; 

    } 

}; 

 

struct compare 

{ 

    bool operator() (Node *l, Node *r) 

    { 

        return (l->freq > r->freq); 

    } 

}; 

 

void storeCodes(struct Node *root, string str) 

{ 

    if (root == NULL) 

        return; 


    if (root->data != '$') 

        codes[root->data] = str; 

    storeCodes(root->left, str + "0"); 

    storeCodes(root->right, str + "1"); 

} 
priority_queue<Node *, vector<Node *>, compare>
    pq;
void HuffmanCodes (int size)
{
    struct Node *left, *right, *top;
    for (auto v = freq.begin() ;
        v != freq.end(); v++)
      pq.push (new Node (v->first, v->second)) ;
    while (pq.size() != 1)
    {
        left = pq.top();
        pq.pop() ;
        right = pq.top();
        pq.pop();
        top = new Node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        pq.push (top) ;
    }
    storeCodes (pq. top(), "");
}
int32_t main()
{

    ios_base::sync_with_stdio (false);
    cin. tie (NULL) ;
#ifndef ONLINE_JUDGE

    freopen ("input.txt","r", stdin) ;
    freopen ("output.txt", "w", stdout);
#endif

    string s;

    getline (cin, s);

    for (int i = 0; i < s.size(); i++)
    {

        freq[s[i]]++;
    }

    HuffmanCodes (s.length()) ;
    for (auto v = codes.begin(); v != codes.end(); v++) 
        cout << v->first << ' ' << v->second << endl; 
    string ans=""; 
    for(auto i:s)
    { 
        ans+=codes[i]; 
    } 
    cout<<"Encoded String is-"<<ans<<"\n";
}

