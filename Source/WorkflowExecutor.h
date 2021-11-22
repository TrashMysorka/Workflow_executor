//
// Created by v.babushkin on 22.11.2021.
//

#ifndef HASH_TABLE_WORKFLOWEXECUTOR_H
#define HASH_TABLE_WORKFLOWEXECUTOR_H

#include "Blocks/Factory.h"
#include "ConfigReader.h"

class WorkflowExecutor{
private:
    IWorker* worker{};
    list<pair<string, string>> priority;
    string filename;
    vector<string> text;
    Factory fact;

    void parse_config();
public:
    explicit WorkflowExecutor(const string& file);


    void execute();

};


#endif //HASH_TABLE_WORKFLOWEXECUTOR_H
