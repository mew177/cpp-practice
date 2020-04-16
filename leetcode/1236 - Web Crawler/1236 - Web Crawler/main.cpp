//
//  main.cpp
//  1236 - Web Crawler
//
//  Created by Wu, Meng Ju on 2020/4/16.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <queue>
#include <set>
#include <string>
using namespace std;

/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */

class Solution {
private:
    string getHostname(string url) {
        bool grab = false;
        string hostname = "";
        for (int i = 0; i < url.size(); i++) {
            if (url[i] == '/' and grab) {
                break;
            } else if (grab) {
                hostname += url[i];
            }
            
            if (url[i] == '/' && url[i-1] == '/') {
                grab = true;
            }
        }
        return ("http://" + hostname);
    }
    
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        string hostname = getHostname(startUrl);
        queue<string> q;
        q.push(startUrl);
        set<string> crawled;
        crawled.insert(startUrl);
        
        while (!q.empty()) {
            string s = q.front();
            q.pop();
            vector<string> urls = htmlParser.getUrls(s);
            for (string url : urls) {
                if (url.find(hostname) != std::string::npos) {
                    if (crawled.find(url) == crawled.end()) {
                        crawled.insert(url);
                        q.push(url);
                    }
                }
            }
        }
        
        vector<string> ans;
        for (set<string>::iterator it=crawled.begin(); it != crawled.end(); ++it) {
            ans.push_back(*it);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
