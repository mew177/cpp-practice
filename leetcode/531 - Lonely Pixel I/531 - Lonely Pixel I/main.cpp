//
//  main.cpp
//  531 - Lonely Pixel I
//
//  Created by Wu, Meng Ju on 2020/4/24.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    bool search(int i, int j, vector<vector<char>>& picture, vector<vector<bool>> & visited) {
        visited[i][j] = true;
        bool islonely = true;
        // search row
        for (int x = 0; x < picture.size(); x++) {
            if (picture[x][j] == 'B' and x != i) {
                // a black pixel but not itself
                islonely = false;
                // also mark this new black pixel as visited
                visited[x][j] = true;
            }
        }
        
        // search col
        for (int y = 0; y < picture[0].size(); y++) {
            if (picture[i][y] == 'B' and y != j) {
                // a black pixel but not itself
                islonely = false;
                // also mark this new black pixel as visited
                visited[i][y] = true;
            }
        }
        return islonely;
    }
    
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int r = picture.size();
        int c = picture[0].size();
        // mark visited 'B' as true
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        
        int count = 0;
        for (int i = 0; i < picture.size(); i++) {
            for (int j = 0; j < picture[0].size(); j++) {
                if (picture[i][j] == 'B' && !visited[i][j]) {
                    // if pixel is 'B' and hasn't been visited
                    if (search(i, j, picture, visited)) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
