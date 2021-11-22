//
// Created by v.babushkin on 22.11.2021.
//

#include "WorkflowExecutor.h"
WorkflowExecutor::WorkflowExecutor(const string& file) {
    filename = file;
}


void WorkflowExecutor::parse_config() {
    ConfigReader reader(filename);
    priority = reader.read_config();
}

void WorkflowExecutor::execute() {
    parse_config();
    for(const auto& it : priority){
        worker = fact.createWorker(it.first, it.second);
        worker->do_work(text);
        if(it.first != "writefile"){
            text = worker->get_result();
        }
    }
}