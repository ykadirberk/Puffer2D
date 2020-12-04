#include "AnimationData.h"
AnimationData::AnimationData(string path) {
    datafile.open(path, ifstream::in);
    vector<string> lines;
    istringstream datahandler;
    while (!datafile.eof()) {
        string store;
        getline(datafile, store);
        lines.push_back(store);
    }
    datahandler.str(lines[0]);
    datahandler >> scale_rule.x >> scale_rule.y;
    printf("-[ANIMATOR] x: %lf, y: %lf\n", scale_rule.x, scale_rule.y);
    string name;
    animator::pair timer = {0,0};
    vector<animator::pair> pairs;
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
    printf("-[ANIMATOR] keys.size(): %d\n", keys.size());
    for (int i = 0; i < keys.size(); i++) {
        printf("-[ANIMATOR]%s\n", keys[i].c_str());
        for (int j = 0; j < at(keys[i]).size(); j++) {
            printf("-[ANIMATOR] x: %lf, y: %lf\n", at(keys[i])[j].x, at(keys[i])[j].y);
        }
    }
}

AnimationData::~AnimationData() {

}

vector<animator::pair> AnimationData::at(string key) {
    for (int i = 0; i < keys.size(); i++) {
        if (keys[i].find(key) != string::npos) {
            return values[i];
        }
    }
    vector<animator::pair> empty_pair;
    return empty_pair;
}

animator::pair AnimationData::GetScaleRule() {
    return scale_rule;
}