#include "SheetAnimator.h"

SheetAnimator::SheetAnimator(string path) {
    datafile.open(path, ifstream::in);
    istringstream datahandler;
    string a;
    string name;
    bool check = false, bf = false;
    vector<pos> p;
    p.clear();
    eSheet es;
    getline(datafile, a);
    while(!datafile.eof()) {
        while (check) {
            getline(datafile, a);
            char* dn;
            strcpy(dn, a.c_str());
            if (dn[0] == '[') {
                check = false;
                es.positions = p;
                p.clear();
                database.insert({es.name,es});
                es.clear();
                break;
            }
            datahandler.str(a);
            pos n;
            datahandler >> n.x >> n.y;
            p.push_back(n);
        }

        while (!check) {
            datahandler.str(a);
            char* aa = NULL;
            datahandler >> aa;
            if (aa[0] == '#') break;
            if (aa[0] == '[') {
                es.name = aa;
            } else if (!bf) {
                string st = aa;
                istringstream isst;
                isst.str(st);
                isst >> es.template_size.x;
                datahandler >> es.template_size.y;
                bf = true;
                getline(datafile, a);
                break;
            }
            aa = NULL;
            datahandler >> aa;
            if (aa[0] != '#') {
                es.rule_set = true;
                string st = aa;
                istringstream isst;
                isst.str(st);
                isst >> es.rule;
                check = true;
            }
        }
        
        
    }
    
}

SheetAnimator::~SheetAnimator() {

}