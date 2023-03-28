#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

const int CAPACITY = 1000;

unsigned int hash_function(string s) {
    const char* Cstring = s.c_str();
    unsigned int h = 0;
    for (int i=0; Cstring[i] != '\0'; i++)
        h += (Cstring[i]*(i+1));
    return h % CAPACITY;
}

int main(int argc, char **argv)
{
    fstream fin;
    vector<vector<string>> hashTable(CAPACITY);
    vector<vector<string>> pwdTable(CAPACITY);
    // string pwdTable[CAPACITY] = {""};
    // char pwdTable[CAPACITY][] = {""};
    fin.open("userInfo.csv", ios::in);
    vector<string> row;
    string line, word;
    unsigned int key;
    while (!fin.eof()) {
        int x =1;
        row.clear();
        getline(fin, line);
        stringstream s(line);
        while (getline(s, word, ',')) {
            if(x==1)
            {
                key = hash_function(word);
                hashTable[key].push_back(word);
                x=0;
            }

            else{
                word.pop_back();
                pwdTable[key].push_back(word);            
            }
        }
    }

    string username = "";
    cout << "Enter the Username "<<endl;
    cin >> username;
    key = hash_function(username);
    

     for (int i=0;i<hashTable[key].size();i++)                                                 
     {
        if(hashTable[key][i] == username)
        {
          string pwd;
          cout<<"Enter The Password:"<<endl;
          cin>>pwd;
                                                                       
          if(pwdTable[key][i]==pwd)
          {
            cout<<"Login successful";
            return 0; 
          }

          else{
            cout<<"Incorrect password";
            return 0 ;
          }
        }

     }
    cout<<"Name not found"<<endl;


    return 0;
}