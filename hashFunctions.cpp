#include <iostream>
using namespace std;

int hashFunction(string s, int size){
    int sum = 0;
    for (int i = 0; i < s.size(); i++) sum += int(s[i]);
    return sum%size;
    }

int main(){
    cout << "Hello world!" << endl;
    cout << hashFunction("Steve",12) << endl;
    cout << hashFunction("spark",12);
    return 0;
}