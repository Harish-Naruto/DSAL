#include <iostream>
using namespace std;
class node
{
private:
    string name;
    string telephone;
    int key;

public:
    node()
    {
        key = 0;
    }
    friend class hashing;
};
int ascii_generator(string s)
{
    int sum = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        sum = sum + s[i];
    }
    return sum % 100;
}
class hashing
{
private:
    node data[100];
    string n;
    string tele;
    int k;
    int index;
    int size;

public:
    hashing()
    {
        k = 0;
    }
    void create_record(string n, string tele)
    {
        size = 100;
        k = ascii_generator(n);
        index =
            k % size;
        for (int j = 0; j < size; j++)
        {
            if (data[index].key == 0)
            {
                data[index].key = k;
                data[index].name = n;
                data[index].telephone = tele;
                break;
            }
            else
            {
                index = (index + 1) % size;
            }
        }
    }
    void search_record(string name)
    {
        size = 100;
        int index1, k, flag = 0;
        k = ascii_generator(name);
        index1 = k % size;
        for (int a = 0; a < size; a++)
        {
            if (data[index1].key == k)
            {
                flag = 1;
                cout << "\nRecord Found\n";
                cout << "Name : "<<data[index1].name<<endl; cout<<" Telephone: "<<data[index1].telephone<<endl; break;  
            }
            else
            {
                index1 = (index1 + 1) % size;
            }
        }
        if (flag == 0)
        {
            cout << "Record Not Found";
        }
    }
    void delete_record(string name)
    {
        size = 100;
        int index1, key, flag = 0;
        key = ascii_generator(name);
        index1 = key % size;
        for (int a = 0; a < size; a++)
        {
            if (data[index].key == key)
            {
                flag = 1;
                data[index1].key = 0;
                data[index1].name = " ";
                data[index1].telephone = " ";
                cout << "\nRecord Deleted SuccessFully !"<<endl; break;  
            }
            else
            {
                index1 = (index1 + 1) % size;
            }
        }
        if (flag == 0)
        {
            cout << "\n Record Not Found";
        }
    }
    void update_record(string name)
    {
        size = 100;
        int index1, key, flag = 0;
        key = ascii_generator(name);
        index1 = key % size;
        for (int a = 0; a < size; a++)
        {
            if (data[index1].key == key)
            {
                flag = 1;
                break;
            }
            else
            {
                index1 = (index1 + 1) % size;
            }
        }
        if (flag == 1)
        {
            cout << "Enter The New Telephone Number ::";
            cin >> tele;
            data[index1].telephone = tele;
            cout << "\n Record Updated SuccessFully";
        }
    }
    void display_record()
    {
        size = 100;
        cout << "\t Name \t\t Telephone";
        for (int a = 0; a < size; a++)
        {
            if (data[a].key != 0)
            {
                cout << "\n\t" << data[a].name << "\t\t\t" << data[a].telephone;
            }
        }
    }
};
int main()
{
    hashing s;
    string name;
    string telephone;
    int choice;
    int x;
    bool loop = 1;
    while (loop)
    {
        cout << "\n------------------------------------------------------------------------ "<<endl;  
        cout<<"\n Telephone book databse "<<endl; 
        cout<<"\n-- -- -- -- -- -- -- -- -- -- --"<<endl; 
        cout<<"\n 1. Create Record "<<endl; 
        cout<<"\n 2.Display Record "<<endl; 
        cout<<"\n 3.Search Record "<<endl; 
        cout<<"\n 4.Update Record "<<endl; 
        cout<<"\n 5.delete Record "<<endl; 
        cout<<"\n 6.Exit "<<endl; 
        cout<<"\n Enter Your Choice : "<<endl; 
        cin>>choice;  
        switch (choice)
        {
        case 1:
            cout << "\n Enter Name:";
            cin >> name;
            cout << "\n Enter telephone Number:";
            cin >> telephone;
            s.create_record(name, telephone);
            break;
        case 2:
            s.display_record();
            break;
        case 3:
            cout << "\n Enter The Name:";
            cin >> name;
            s.search_record(name);
            break;
        case 4:
            cout << "\n Enter The Name:";
            cin >> name;
            s.update_record(name);
            break;
        case 5:
            cout << "\n Enter The Name To delete:";
            cin >> name;
            s.delete_record(name);
            break;
        case 6:
            loop = 0;
            break;
        default:
            cout << "\n You Enter Something Wrong!";
            break;
        }
    }
    return 0;
}
