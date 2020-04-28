//
//  main.cpp
//  535 - Encode and Decode TinyURL
//
//  Created by Wu, Meng Ju on 2020/4/25.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
private:
    
    pair<string, string> parse(string longURL) {
        // pair< https://leetcode.com, /problems/design-tinyurl >
        string home = "", sub = "";
        bool meet = false;
        for (int i = 1; i < longURL.size(); i++) {
            if (longURL[i] == '/' && longURL[i-1] == '/')
                // first '/' after meeting '//' should be the home net
                meet = true;
            else if (longURL[i] == '/' && meet) {
                home = longURL.substr(0, i+1);
                sub = longURL.substr(i+1, longURL.size()-i);
                break;
            }
        }
        return { home, sub };
    }
    
public:
    
    hash<string> str_hash;
    // <encodedURL, longURL>
    map<string, string> mapper;
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        auto [home, sub] = parse(longUrl);
        auto encoded = to_string(str_hash(sub));
        // [ home, sub ] : [ "https://leetcode.com/", "problems/design-tinyurl" ]
        mapper[encoded] = sub;
        return home + encoded;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        auto [home, encoded] = parse(shortUrl);
        return home + mapper[encoded];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
