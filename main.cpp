#include <iostream>
#include <string>
#include <fstream>
#include <utility>
#include <vector>
#include <list>
#include "Source/WorkflowExecutor.h"
#include <typeinfo>

using namespace std;



int main() {
    string s;
    int k;
    cout << typeid(k).name() << endl;
    vector<string> h (3, "lololololol \n");
    //WriteFile w1("output.txt");
    //w1.do_work(h);
    //IWorker* w = IWorker::createWorker("writefile", "output.txt");
    //(*w).do_work(h);
    //ifstream in("input.txt");
    //cout << in.is_open();
    WorkflowExecutor w1("config.txt");
    w1.execute();
    return 0;
}
