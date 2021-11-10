//
// Created by Admin on 02.11.2021.
//
#include <string>
#include <fstream>
#include <utility>
#include <vector>
#include <list>
#include <unordered_map>
#include <map>
enum Worker_ID { ReadFile_ID=0, Writefile_ID, Grep_ID, Sort_ID, Replace_ID, Dump_ID, Count_ID};

using namespace std;





class ConfigReader{
private:
    string workers, args;
    int id{};
    list<pair<string, string>> priority;
    map<int, pair<string, string>> jobs;
    ifstream file;

    void separate_ids(const string& str);


    void separate(const string& str);


    void read_desc();


    void read_csed();
public:
    explicit ConfigReader(const string& filename);


    list<pair<string, string>> read_config();

};


class IWorker{
protected:
    vector<string> args;
    vector<string> text;
public:
    virtual void parse_args() = 0;


    virtual void do_work(vector<string> text) = 0;

    virtual vector<string> get_result() = 0;

    static IWorker* createWorker(const string& Worker_name, const string& arguments);
};

class ReadFile : public IWorker{
private:
    ifstream file;
    void parse_args() override;
public:
     explicit ReadFile(const string& arguments);


    void do_work(vector<string> txt) override;


    vector<string> get_result() override;
};


class WriteFile : public IWorker{ //don't work
private:
    vector<string> get_result() override;
    ofstream file;
    void parse_args() override;
public:
    explicit WriteFile(const string& arguments);




    void do_work(vector<string> txt) override;


};


class Grep : public IWorker{
private:

    string word;
    void parse_args() override;
public:
    explicit Grep(const string& arguments);

    void do_work(vector<string> txt) override;


    vector<string> get_result() override;
};


class Sort : public IWorker{
private:
    list<string> words;

    static bool size_comp(const string& first, const string& second);


    void get_words(const string& str);


    void parse_args() override;
public:
    explicit Sort(const string& args);
    void do_work(vector<string> txt) override;


    vector<string> get_result() override;
};


class Replace : public IWorker{
private:
    string word1, word2;


    vector<string> words;


    void get_words(const string& str);


    string replace_words();


    void parse_args() override;
public:
    explicit Replace(const string& arguments);





    void do_work(vector<string> txt) override;


    vector<string> get_result() override;
};


class Dump : public IWorker{
private:
    ofstream file;

    void parse_args() override;
public:
    explicit Dump(const string& arguments);





    void do_work(vector<string> txt) override;


    vector<string> get_result() override;
};


class Count : public IWorker{
private:
    int amount;
    vector<string> words;
    string word;


    void get_words(const string& str);


    void parse_args() override;

public:
    explicit Count(const string& args);


    void do_work(vector<string> txt) override;


    vector<string> get_result() override;
};


class WorkflowExecutor{
private:
    IWorker* worker{};
    list<pair<string, string>> priority;
    string filename;
    vector<string> text;

    void parse_config();
public:
    explicit WorkflowExecutor(const string& file);


    void execute();

};
