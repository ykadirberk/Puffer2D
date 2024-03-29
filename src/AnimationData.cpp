#include "AnimationData.h"

Puffer::AnimationData::AnimationData(string path) {
    datafile.open(path, ifstream::in); //Opens the file to read-only
    vector<string> lines; //This variable will store every line of read file
    istringstream datahandler; //To perform actions on stored data.
    while (!datafile.eof()) {
        string store;
        getline(datafile, store);
        lines.push_back(store);
    } //Used to read all lines
    datahandler.str(lines[0]); //As the first line is the rule of scale (2 dimensional size of a tile) it is read first
    datahandler >> scale_rule.x >> scale_rule.y;
    printf("-[ANIMATOR] x: %lf, y: %lf\n", scale_rule.x, scale_rule.y);
    string name; //To name keys for mapping
    animator::pair timer = {0,0}; //its firt use is determining the time constant. It will be used to contain positions for others.
    vector<animator::pair> pairs; //Stores key's values.
    for(int i = 1; i < lines.size(); i++) {
        if (lines[i][0] == '-') {
            keys.push_back(name);
            values.push_back(pairs);
            pairs.clear();
            break;
        }
        if (lines[i][0] == '[') {
            if (i != 1) {
                keys.push_back(name);
                values.push_back(pairs);
                pairs.clear();
            }
            timer = {0,0};
            datahandler.clear();
            datahandler.str(lines[i]);
            datahandler >> name >> timer.x;
            pairs.push_back(timer);
            continue;
        }
        datahandler.clear();
        datahandler.str(lines[i]);
        timer = {0,0};
        datahandler >> timer.x >> timer.y;
        pairs.push_back(timer);
    }
    printf("-[ANIMATOR] keys.size(): %d\n", keys.size()); //Prints processed data as debug-log
    for (int i = 0; i < keys.size(); i++) {
        printf("-[ANIMATOR]%s\n", keys[i].c_str());
        for (int j = 0; j < at(keys[i]).size(); j++) {
            printf("-[ANIMATOR] x: %lf, y: %lf\n", at(keys[i])[j].x, at(keys[i])[j].y);
        }
    }
}

Puffer::AnimationData::~AnimationData() {
    values.clear();
    keys.clear();
    printf("[DECONSTRUCT-LOG] AnimationData class released.\n");
}

//This function is used to create a type of map.
vector<Puffer::animator::pair> Puffer::AnimationData::at(string key) {
    for (int i = 0; i < keys.size(); i++) {
        if (keys[i].find(key) != string::npos) {
            return values[i];
        }
    }
    vector<animator::pair> empty_pair;
    return empty_pair;
}

Puffer::animator::pair Puffer::AnimationData::GetScaleRule() {
    return scale_rule;
}