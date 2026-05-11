#include <iostream>
#include <string>
using namespace std;

int main(){
    string key = "MEGABUCK";
    string plaintext;
 
    cout<<"enter plaintext"<<endl;
    getline(cin, plaintext);

    int keylen = key.length();
    int textlen = plaintext.length();

    int rows = textlen / keylen;

    if (textlen % keylen != 0){
        rows++;
    }

    char matrix[rows][keylen];
    int idx = 0;

    for (int i = 0; i < rows; i++){
        for(int j = 0; j < keylen; j++){
            if (idx < textlen){
                matrix[i][j] = plaintext[idx];
                idx++;
            }
            else{
                matrix[i][j] = 'X';
            }
            }
        }

    //1. plaintext matrix
    cout<<"plaintext matrix: "<<endl;
    for(int i = 0; i <keylen; i++){
        cout<<key[i]<<" ";
    }
    cout<<endl;
    for(int i =0; i < keylen; i++){
        cout << "- ";
    }
    cout << endl;

    // print matrix
    for( int i =0; i <rows; i++){
        for( int j =0; j <keylen; j++){
            cout << matrix[i][j] <<" ";
        }
        cout << endl;
    }


    //2. Cipher text
    string ciphertext = "";
    for(char c = 'A'; c <= 'Z'; c++){
        for(int i = 0; i < keylen; i++){
            if (toupper(key[i]) == c){
                for(int j = 0; j < rows; j++){
                    ciphertext += matrix[j][i];
                }
            }
        }

    }
    cout<<"ciphertext: "<<ciphertext<<endl;

    //3. Decryption
    char decmatrix[rows][keylen];
    idx = 0;
    for(char c = 'A'; c <= 'Z'; c++){
        for(int i = 0; i < keylen; i++){
            if (toupper(key[i]) == c){
                for(int j = 0; j < rows; j++){
                    decmatrix[j][i] = ciphertext[idx];
                    idx++;
                }
            }
        }
    }

    // read the decrypted text from the matrix
    string decryptedtext = "";
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < keylen; j++){
            decryptedtext += decmatrix[i][j];
        }
    }

    while(  decryptedtext.back() == 'X' && !decryptedtext.empty()){
        decryptedtext.pop_back();
    }

    cout<<"decrypted text: "<<decryptedtext<<endl;
}