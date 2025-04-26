#include<bits/stdc++.h>
using namespace std;
struct Node
{
    string name;
    vector<Node*> nodes;
    Node (string name)
    {
        this->name = name;
    }
};
Node* constructsection(int i){
    string sectionname;
    cout<<"enter the name of "<<i+1<<" section: ";
    cin>>sectionname;
    Node* section = new Node(sectionname);
    return section;
}
Node* constructchapter(int j){
    string chapname;
    cout<<"enter the name of "<<j+1<<" chapter: ";
    cin>>chapname;
    Node* chapter = new Node(chapname);
    int n;
    cout<<"enter the number of section: ";
    cin>>n;
    for(int i = 0; i<n ;i++){
        Node* child = constructsection(i);;
        chapter->nodes.push_back(child);
    }
    return chapter;
}

Node* constructbook()
{
    string rootData;
    cout << "Enter the name of book here-\n";
    cin >> rootData;
    Node* root = new Node(rootData);

    int n;
    cout << "Enter the number of chapter-\n";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        Node* child = constructchapter(i);
        root->nodes.push_back(child);
    }

    return root;
}

void display(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    cout<<"---------------book----------------"<<endl;
    cout << root->name << " : "<<endl;
    for(int i = 0; i<root->nodes.size();i++){
        Node* chapter = root->nodes[i];
        cout<<"chapter: "<<chapter->name;
        cout<<endl;
        for(int j = 0 ; j<chapter->nodes.size();j++){
            Node* section = chapter->nodes[j];
            cout<<j+1<<") "<<section->name<<endl;
        }
    }

    
}

int main()
{
    Node* book = constructbook();
    display(book);
    return 0;
}