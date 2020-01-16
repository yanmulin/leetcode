class Solution {
private:
    vector<string> split(const string &s, char delim) {
        vector<string> elems;
        stringstream ss(s);
        string item;
        while(getline(ss, item, delim)) {
            elems.push_back(item);
        }
        return elems;
    }
public:
    string simplifyPath(string path) {
        vector<string> elems = split(path, '/');
        int ignore = 0;
        string result;
        for (int i=elems.size()-1;i>=0;i--) {
            if (elems[i] == "." || elems[i] == "") 
                continue;
            if (elems[i] == "..") {
                ignore ++;
                continue;
            }
            if (ignore > 0) {
                ignore --;
                continue;
            }
            if (result.size() == 0) {
                result = elems[i];
            } else {
                result = elems[i] + '/' + result;
            }
        }
        result = "/" + result;
        return result;
    }
};
