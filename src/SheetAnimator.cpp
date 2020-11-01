#include "SheetAnimator.h"

SheetAnimator::SheetAnimator(string path) {
    datafile.open(path, ifstream::in);
    istringstream datahandler;
    string store;
    eSheet e_one;
    bool b_one = false;
    while(!datafile.eof()) {
        getline(datafile, store);
        datahandler.str(store);
        cout << "[ON-WAY-TO-BE-PROCESSED] "<< store << endl;
        if (!b_one) {
            while(!datahandler.eof()) {
                string s_one;
                datahandler >> s_one;
                cout << "[PRE-PROCESS] " << s_one << endl;
                char* c_one = new char[s_one.length()];
                strcpy(c_one, s_one.c_str());
                cout << "[PROCESSING] " << c_one << endl;
                if(c_one[0] == '#') {
                    cout << "[COMMENT-DETECTED] " << c_one << endl;
                    break;
                } else if (c_one[0] == '[') {
                    e_one.name = s_one;
                    cout << "[NAME-RECOGNISED] "<<s_one << " defined." << endl;
                    b_one = true;
                } else {
                    istringstream tempruler;
                    tempruler.str(store);
                    tempruler >> e_one.template_size.x >> e_one.template_size.y;
                    cout << "[TEMPLATE-RULE-SET] " << e_one.template_size.x << ' ' << e_one.template_size.y << endl;
                }
            }
        } else {
            string s_one;
            datahandler >> s_one;
            char* c_one = new char[s_one.length()];
            strcpy(c_one, s_one.c_str());
            if (c_one[0] != '[' && c_one[0] != '#') {
                
            }
        }

        
        
    }
    
}

SheetAnimator::~SheetAnimator() {

}