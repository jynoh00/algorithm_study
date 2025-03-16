// 대칭 키 암호화
// RC4 algorithm

#include <iostream>
#include <cstring>
#include <vector>
#include <sstream>

using namespace std;

int main(){
    char S[256], K[256];
    int i, t;
    
    char key[] = "key";
    string plainText;

    cout << "plain text input : ";
    cin >> plainText;
    

    vector<char> KeyStream(plainText.size()); // strlen, KeyStream()
    cout << "key : " << key << endl;
    cout << "plain text : " << plainText << endl;

    // init_
    for (i = 0; i < 256; i++){
        S[i] = i;
        K[i] = key[i%strlen(key)];
    } 
    
    int j = 0;
    for (i = 0; i < 256; i++){
        j = (j + S[i] + K[i]) % 256;
        swap(S[i], S[j]); // swap
    }

    i = j = 0;

    //encrypt
    for (int k = 0; k < plainText.size(); k++){
        i = (i+1)%256;
        j = (j+S[i])%256;
        swap(S[i], S[j]);

        t = (S[i] + S[j])%256;
        KeyStream[k] = S[t]; // KeyStream[]
        plainText[k] ^= S[KeyStream[k]]; // ^=

        cout << (k+1) << "'s keystream : " << (unsigned int)KeyStream[k] << endl;
    }

    // 16진수로 암호화된 문자를 출력
    cout << "encrypted plain text (hex): ";
    for (int k = 0; k < plainText.size(); k++) {
        printf("%02x ", (unsigned char)plainText[k]); // 16진수로 출력
    }
    cout << endl;

    //decrypt
    for (int k = 0; k < plainText.size(); k++){
        plainText[k] ^= S[KeyStream[k]];
    }

    cout << endl << "decrypted plain text  :  " << plainText << endl;
    exit(0);
}