//
// Created by v.babushkin on 22.11.2021.
//
#include <string>
#include <fstream>
#include <utility>
#include <vector>
#include <list>
#include <unordered_map>
#include <map>
#ifndef HASH_TABLE_IWORKER_H
#define HASH_TABLE_IWORKER_H

using namespace std;
class IWorker{
protected:
    vector<string> args;
    vector<string> text;
public:
    virtual void parse_args() = 0;


    virtual void do_work(vector<string> text) = 0;

    virtual vector<string> get_result() = 0;


};


#endif //HASH_TABLE_IWORKER_H
