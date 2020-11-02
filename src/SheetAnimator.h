#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <SFML/Graphics.hpp>

using namespace std;

struct pos {
    int x;
    int y;
};

struct eSheet {
        string name;
        bool rule_set = false;
        double rule;
        vector<pos> positions;
        void clear() {
            name.clear();
            rule_set = false;
            rule = 0;
            positions.clear();
        }
};


class SheetAnimator {
    public:
        SheetAnimator(string path);
        ~SheetAnimator();
        pos template_size;
    private:
        ifstream datafile;
        map<string, eSheet> database;
};