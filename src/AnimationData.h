#pragma once
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

//Aim of this class is to classify the data to be used later.

namespace animator {
    struct pair {
        double x;
        double y;
    };
}

class AnimationData {
    public:
        AnimationData(string path);
        ~AnimationData();

        vector<animator::pair> at(string key);
        animator::pair GetScaleRule();
    private:
        animator::pair scale_rule;
        ifstream datafile;
        vector<vector<animator::pair>> values;
        vector<string> keys;

};