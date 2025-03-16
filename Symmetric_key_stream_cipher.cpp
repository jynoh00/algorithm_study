// Symmetric key Stream Cipher = RC4
// simple하게

#include <iostream>
#include <string>

using namespace std;

int main(){
    string plain_txt = "안녕하세요";
    string key = "100101001010001";
    string cipher_txt = "";
    for (int i = 0; i < plain_txt.size(); i++){
        cipher_txt += plain_txt[i]^key[i];
        cout << "#";
    }
    cout << endl << cipher_txt << endl;

    string key_s, ans;
    cout << "키 입력 : " << endl;
    cin >> key_s;
    for (int i = 0; i < key_s.size(); i++){
        ans += key_s[i]^cipher_txt[i];
    }
    cout << "복호 결과 : ";
    cout << ans << endl;
}