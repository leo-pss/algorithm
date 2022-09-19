#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> files;
        vector<vector<string>> result;

        for (auto path : paths) {
            stringstream ss(path);
            string root;
            string child;
            getline(ss, root, ' ');
            while (getline(ss, child, ' ')) {
                string name = root + '/' + child.substr(0, child.find('('));
                string content = child.substr(child.find('(')+1, child.find(')')-child.find('(')-1);
                files[content].push_back(name);
            }
        }

        for (auto file : files) {
            if (file.second.size()>=2) result.push_back(file.second);
        }

        return result;
    }
};