#include <iostream>
#include <string>
#include <fstream>
#include <utility>
#include <vector>
#include <list>
#include "workflow.h"

using namespace std;



int main() {
    vector<string> h (3, "lololololol \n");

    //IWorker* w = IWorker::createWorker("writefile", "output.txt");
    //(*w).do_work(h);
    WorkflowExecutor w1("config.txt");
    w1.execute();
    return 0;
}
