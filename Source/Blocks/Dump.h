//
// Created by v.babushkin on 22.11.2021.
//

#ifndef HASH_TABLE_DUMP_H
#define HASH_TABLE_DUMP_H
#include "IWorker.h"

class Dump : public IWorker{
private:
    ofstream file;

    void parse_args() override;
public:
    explicit Dump(const string& arguments);





    void do_work(vector<string> txt) override;


    vector<string> get_result() override;
};




#endif //HASH_TABLE_DUMP_H
