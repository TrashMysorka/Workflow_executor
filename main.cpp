#include <iostream>
#include <string>
#include <fstream>
#include <utility>
#include <vector>
#include <list>
#include "workflow.h"

using namespace std;



int main() {
    vector<string> s;
    s.emplace_back("input.txt");
    ReadFile r1(s);
    r1.parse_args();
    r1.do_work();

    s = r1.get_result();
    vector<string> s1;
    s1.emplace_back("output.txt");
    WriteFile w(s1);
    w.parse_args();
    w.do_work(s);
    for (const auto& it : s){
        cout <<"jopa = " << it << endl;
    }

    return 0;
}
