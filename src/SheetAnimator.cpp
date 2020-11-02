#include "SheetAnimator.h"

SheetAnimator::SheetAnimator(string path) {
    datafile.open(path, ifstream::in);
    istringstream datahandler;
    string store;
    eSheet e_one;
    bool b_one = false;
    while(!datafile.eof()) {
        getline(datafile, store);
        datahandler.clear();
        datahandler.str(store);
        cout << "[ON-WAY-TO-BE-PROCESSED] "<< store << endl << "--------STATE OF B_ONE--------:  " << b_one << endl;
        //cout << "[STATE-OF-DATAHANDLER] " << datahandler.eof() << endl;
        if (b_one) {
            string s_one;
            datahandler >> s_one;
            cout << "[PRE-PROCESS] " << s_one << endl;
            char* c_one = new char[s_one.length()];
            strcpy(c_one, s_one.c_str());
            cout << "[PROCESSING] " << c_one << endl;
            if (c_one[0] != '[' && c_one[0] != '#') {
                pos a;
                istringstream iss_2;
                iss_2.str(s_one);
                iss_2 >> a.x;
                datahandler >> a.y;
                e_one.positions.push_back(a);
                cout << "[POSITION-SET] "<< a.x << ' ' << a.y << endl;
                cout << "--------STATE OF FILE--------:  " << datafile.eof() << endl;
            } else if (c_one[0] == '[') {
                database.insert({e_one.name, e_one});
                e_one.clear();
                b_one = false;
                datahandler.clear();
                datahandler.str(store);
            } 
            if(datafile.eof()) {
                database.insert({e_one.name, e_one});
                e_one.clear();
                b_one = false;
                datahandler.clear();
                break;
            }
        }
        cout << "--------STATE OF B_ONE--------:  " << b_one << endl;
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
                    datahandler.clear();
                    break;
                } else if (c_one[0] == '[') {
                    e_one.name = s_one;
                    cout << "[NAME-RECOGNISED] " << s_one << " defined." << endl;
                    b_one = true;
                } else {
                    istringstream tempruler;
                    tempruler.str(store);
                    tempruler >> template_size.x >> template_size.y;
                    cout << "[TEMPLATE-RULE-SET] " << template_size.x << ' ' << template_size.y << endl;
                }
            }
        }
        
    }
    cout << "[TEMPLATE-SIZE] " << template_size.x << " " << template_size.y << endl;
    cout << database.at("[REGULAR]").positions[0].x << ' ' << database.at("[REGULAR]").positions[0].y << endl;
    cout << database.at("[HOVER]").positions[0].x << ' ' << database.at("[HOVER]").positions[0].y << endl;
    cout << database.at("[PRESSED]").positions[0].x << ' ' << database.at("[PRESSED]").positions[0].y << endl;
}

SheetAnimator::~SheetAnimator() {

}