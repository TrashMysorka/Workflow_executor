//
// Created by Admin on 02.11.2021.
//
#include <string>
#include <fstream>
#include <utility>
#include <vector>
#include <list>
using namespace std;


class IWorker{
protected:
    vector<string> args;
    vector<string> text;
public:
    virtual void parse_args() = 0;


    virtual void do_work(vector<string> text) = 0;



};
class IReturns : public IWorker{
    virtual vector<string> get_result() = 0;

};
class ReadFile : IReturns{
private:
    ifstream file;
public:
     ReadFile(vector<string> arguments);


    void parse_args() override;


    void do_work(vector<string> txt=vector<string>()) override;


    vector<string> get_result() override;
};


class WriteFile : IWorker{ //don't work
private:
    ofstream file;
public:
    WriteFile(vector<string> arguments);

    void parse_args() override;


    void do_work(vector<string> txt) override;


};


class Grep : IReturns{
private:
    string word;
public:
    Grep(vector<string> arguments);


    void parse_args() override;


    void do_work(vector<string> txt) override;


    vector<string> get_result() override;
};