#include <iostream>
#include <unordered_set>
#include <string>
#include <unordered_map>
#include <map>
#include <vector>

using namespace std;

class Transform {
private:
    string str;

    char findUniqueCharUtil() {
        int count[26] = {0};
        for (int i = 0; i < str.size(); ++i) {
            count[tolower(str[i]) - 'a'] += 1;
        }
        char uniqueChar = '\0';
        for (int i = 0; i < str.size(); ++i) {
            if (count[str[i] - 'a'] == 1) {
                uniqueChar = str[i];
                break;
            }
        }
        return uniqueChar;
    }
public:
    // constructor
    Transform(string s):str(s){}

    // find unique character; if not found thorw exception
    void findUniqueChar(){
        char uniqueChar = findUniqueCharUtil();
        try {
            if (uniqueChar == '\0') {
                throw uniqueChar;
            }
            cout << uniqueChar << endl;
        }
        catch (char uniqueChar) {
            cout << "No unique characters!!!" << endl;
        }
    }

    // String transform
    string transformString(){
        // Count and store the count of number of occurrences of each character
        unordered_map< char, vector<char> > umap;
        for(int i=0; i<str.size(); i++){
            umap[tolower(str[i])].push_back(str[i]);
        }

        // Map stores characters in the order of number of occurrences,
        // where key = count; value = vector of characters with that count.
        // Characters occur in the order of appearence in the string
        map<int, vector<char> > m;
        // Loop through the characters in the string to account for occurrence order
        for(int i=0; i<str.size(); i++){
            // Iterator to point at character in the umap
            auto it = umap.find(tolower(str[i]));
            // If character still present in the umap then add to map
            if(it != umap.end()){
                vector<char> temp = it->second;
                int size = temp.size();
                for(char c : temp){
                    m[size].push_back(c);
                }
                // Erase already processed characters.
                umap.erase(tolower(str[i]));
            }
        }

        // to store transformed string
        string res = "";

        for(auto it=m.begin(); it!=m.end(); it++){
            vector<char> temp = it->second;
            for(char c : temp){
                res+=c;
            }
        }
        return res;
    }
};

int main(){
    string input;
    cout<<"Enter a string:"<<endl;
    cin>>input;
    Transform t(input);
    t.findUniqueChar();
    cout << t.transformString() << endl;
    return 0;
}