#include <iostream>
#include <string>
#include <fstream>
#include <utility>
#include <vector>
#include <list>
#include "workflow.h"

using namespace std;



int main() {
    WorkflowExecutor w("config.txt");
    w.execute();
    return 0;
}
