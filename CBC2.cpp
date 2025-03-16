// Cipher Block Chaining.
// Symmetric key crypto. - Block Cyphers.
#include <iostream>
#include <random>
#include <ctime>
#include <vector>

using namespace std;

vector<int> create_vec(int k){
    vector<int> Ks;
    for (int i = 0; i < k; i++) Ks.emplace_back(rand()%2);
    return Ks;
}

vector<vector<int>> blocking(int k, string s){
    vector<vector<int>> bl;
    vector<int> tmp;
    for (int i = 1; i <= s.size(); i++){
        tmp.emplace_back(s[i-1]-48);
        if (i%k==0){
            //cout << tmp[0] << tmp[1] << tmp[2] << ":" << endl;
            bl.emplace_back(tmp);
            tmp.clear();
        }
    }
    return bl;
}

vector<int> encrypto(int k, vector<int> iv, vector<int> sk, vector<vector<int>> bl){
    vector<int> cT;
    vector<int> exc_tmp = iv;
    // for (int i = 0; i < iv.size(); i++){
    //     cout << iv[i] << exc_tmp[i] << endl;
    // }
    for (vector<int> v : bl){
        vector<int> tmp;
        for (int i = 0; i < v.size(); i++){
            int b = v[i]^exc_tmp[i];
            //cout << "v[i]: " << v[i] << "exc_tmp[i]: " << exc_tmp[i] << "b: " << b << endl;
            tmp.emplace_back(b);
        }
        exc_tmp = tmp;
        for (int i = 0; i < exc_tmp.size(); i++) cT.emplace_back(exc_tmp[i]^sk[i]);
    }
    return cT;
}

vector<int> decrypto(vector<int> cp, int k, vector<int> sk, vector<int> iv){
    vector<int> pT;
    vector<int> exc_tmp = iv;
    for (int i = 0; i < cp.size(); i+=k){
        vector<int> tmp;
        for (int j = 0; j < k; j++){
            tmp.emplace_back(cp[i+j]^sk[j]);
        }
        for (int l = 0; l < tmp.size(); l++) pT.emplace_back(exc_tmp[l]^tmp[l]);
        exc_tmp = tmp;
    }
    return pT;
}

int main(){
    srand(static_cast<unsigned int> (time(NULL)));
    const int K = 3;
    vector<int> symmetric_K = create_vec(K);
    vector<int> initial_Vector = create_vec(K);
    string plain_text;
    vector<vector<int>> plain_text_Block;
    vector<int> cipher_text;
    vector<int> decrypt_text;
    
    //input
    cout << "plain Text : ";
    cin >> plain_text;
    plain_text_Block = blocking(K, plain_text);
    cipher_text = encrypto(K, initial_Vector, symmetric_K, plain_text_Block);
    decrypt_text = decrypto(cipher_text, K, symmetric_K, initial_Vector);

    //output
    cout << "K = " << K << endl;
    cout << "Ks = ";
    for (int i : symmetric_K) cout << i << " ";
    cout << endl;
    cout << "IV = ";
    for (int i : initial_Vector) cout << i << " ";
    cout << endl;
    
    cout << "cipher Text : ";
    for (int i = 0; i < cipher_text.size(); i++) cout << cipher_text[i];
    cout << endl;
    
    cout << "Decryption : ";
    for (int i : decrypt_text) cout << i;
    cout << endl;
}