#include <iostream>
#include <string>
using namespace std;

string caesarencrypt(string text, int key){
    string result = "";
    for(int i = 0; i < text.length(); i++){
        char ch = text[i];
        if(isupper(ch))
            result += char((ch + key - 'A') % 26 + 'A');
        else if(islower(ch))
            result += char((ch + key -'a') % 26 + 'a');
        else
        result += ch;
    }
    return result;
}

string caesardecrypt( string cipher, int key){
    key = key % 26;
    string result = "";

    for(int i = 0; i < cipher.length(); i++){
        char ch = cipher[i];
        if (isupper(ch))
            result += char((ch - key - 'A') % 26 + 'A');
        else if(islower(ch))
            result += char((ch - key - 'a') % 26 + 'a');
        else
            result += ch;
    }
return result;
}

int main(){
string text ;
int key;

cout<<"enter text: "<<endl;
getline(cin, text);

cout<<"enter key:"<<endl;
cin>>key;

string encrypted = caesarencrypt(text, key);
cout<<"encrypted text: "<<encrypted<<endl;

string decrypted = caesardecrypt(encrypted, key);
cout<<"decrypted text: "<<decrypted<<endl;

return 0;
}