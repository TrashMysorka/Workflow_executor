//
// Created by v.babushkin on 22.11.2021.
//

#include "Factory.h"
#include "ReadFile.h"
#include "WriteFile.h"
#include "Grep.h"
#include "Sort.h"
#include "Replace.h"
#include "Dump.h"
#include "Count.h"

enum Worker_ID { ReadFile_ID=1, Writefile_ID, Grep_ID, Sort_ID, Replace_ID, Dump_ID, Count_ID};


unordered_map<string, int> worker_names({{"readfile", ReadFile_ID}, {"writefile", Writefile_ID},
                                         {"grep", Grep_ID}, {"sort", Sort_ID}, {"replace", Replace_ID},
                                         {"dump", Dump_ID}, {"count", Count_ID}
});
IWorker* Factory::createWorker(const string& worker_name, const string& arguments) {
    IWorker* p;
    switch(worker_names[worker_name]){
        default:
            throw runtime_error("Factory : this worker doesn't exist");
        case ReadFile_ID:
            p = new ReadFile(arguments);
            break;
        case Writefile_ID:
            p = new WriteFile(arguments);
            break;
        case Grep_ID:
            p = new Grep(arguments);
            break;
        case Sort_ID:
            p = new Sort(arguments);
            break;
        case Replace_ID:
            p = new Replace(arguments);
            break;
        case Dump_ID:
            p = new Dump(arguments);
            break;
        case Count_ID:
            p = new Count(arguments);
            break;
    }
    return p;
}