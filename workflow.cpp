#include "workflow.h"
#include <iostream>
class WorkerFindException : public std::exception
{
    const char * what () const throw ()
    {
        return "This block doesn't exist";
    }
};


class FileError : public std::exception
{
    const char * what () const throw ()
    {
        return "File is not opened";
    }
};


unordered_map<string, int> worker_names({{"readfile", ReadFile_ID}, {"writefile", Writefile_ID},
                                         {"grep", Grep_ID}, {"sort", Sort_ID}, {"replace", Replace_ID},
                                         {"dump", Dump_ID}, {"count", Count_ID}
                                        });

IWorker* IWorker::createWorker(const string& worker_name, const string& arguments) {
    IWorker* p;
    switch(worker_names[worker_name]){
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
        default:
            throw WorkerFindException();

    }
    return p;
}


ConfigReader::ConfigReader(const string& filename) {
    file.open(filename, ifstream::in);
    if (!file.is_open()) throw FileError();
}


void ConfigReader::separate(const string& str) {
    for (char i : str){
        if(i != ' ') {
            workers += i;
        }
        else{
            break;
        }
    }
    size_t pos = str.find(' ') + 1;
    if (pos != string::npos){
        args = str.substr(pos);
    }
    else{
        args = " ";
    }
}


void ConfigReader::separate_ids(const string& str) {
    string num;
    string words;
    cout << str << endl;
    for(char it : str){
        if(isdigit(it)){
            num += it;
        }
        else break;
}
        id = stoi(num);
    separate(str.substr(str.find('=') + 2));
}


void ConfigReader::read_desc() {
    string str;

    getline(file, str);
    if(str!="desc"){
        while(str!="desc" && file){
            getline(file, str);
        }
    }
    getline(file, str);
    while(str != "csed"){
        separate_ids(str);
        jobs[id] = make_pair(workers, args);
        workers.clear();
        args.clear();
        getline(file, str);
        }
}


void ConfigReader::read_csed() {
    string str;
    string num;
    getline(file, str);
    str += " ";
    for (char i : str){
        if(isdigit(i)){
            num += i;
        }
        else{
            if (!num.empty()){
                id = stoi(num);
                priority.push_back(jobs[id]);
                num.clear();
            }


        }
    }
}


list<pair<string, string>> ConfigReader::read_config() {
    read_desc();
    read_csed();
    return priority;
}


ReadFile::ReadFile(const string& arguments){
    string s;
    args.push_back(s);
    for (char i : arguments){
        args[0].push_back(i);
    }

}

void ReadFile::parse_args(){
    string filename = args[0];
    file.open(filename, ifstream::in);
    if(!file){
        throw FileError();
    }
}


void ReadFile::do_work(vector<string> txt){
    parse_args();
    string str;
    while(!file.eof() && file){
        getline(file, str);
        if (!str.empty()){
            str += '\n';
            text.push_back(str);
        }
    }
}


vector<string> ReadFile::get_result(){
    return text;
}


WriteFile::WriteFile(const string& arguments){
    string s;
    args.push_back(s);
    for (char i : arguments){
        args[0].push_back(i);
    }
}


vector<string> WriteFile::get_result() {
    return vector<string>();
}


void WriteFile::parse_args(){
    string filename = args[0];
    file.open(filename);
    if(!file){
        throw FileError();
    }
}


void WriteFile::do_work(vector<string> txt){
    parse_args();
    for (const auto& it : txt){
        cout << it;
        file << it;
    }
}


Grep::Grep(const string& arguments) {
    string s;
    args.push_back(s);
    for (char i : arguments){
        args[0].push_back(i);
    }
}


void Grep::parse_args() {
    word = args[0];
}


void Grep::do_work(vector<string> txt){
    parse_args();
    string rword;
    for (const auto& it : txt){
        for (const auto& it1 : it){
            if(it1 != ' ' && it1 != '\n' /*&& it1 != it.end()*/){
                rword += it1;
            }
            else{
                if (rword == word){
                    text.push_back(it);
                    rword = "";
                    break;
                }
                else{
                    rword = "";
                }
            }
        }
    }
}


vector<string> Grep::get_result() {
    return text;
}

Sort::Sort(const string& args) {
}
void Sort::parse_args() {}


void Sort::get_words(const string& str){
    string got_word;
    string new_str = str + " ";

    for(char it : new_str){
        if(it != ' ' && it!= '\n'){
            got_word += it;
        }
        else{
            if(!got_word.empty()){
                got_word += " ";
                words.push_back(got_word);
                got_word = "";
            }

        }
    }
}


bool Sort::size_comp(const string &first, const string &second) {
    if (first.size() == second.size()){
        return first < second;
    }
    else return first.size() < second.size();
}


void Sort::do_work(vector<string> txt) {
    parse_args();
    for(const auto& it : txt){
        get_words(it);
    }
    if(words.size() == 1){
        text = txt;
        return;
    }
    words.sort(size_comp);
    for(const auto& it : words){
        text.push_back(it);
    }
}


vector<string> Sort::get_result() {
    return text;
}


Replace::Replace(const string& arguments) {
    string s;
    args.push_back(s);
    args.push_back(s);
    int i = 0;
    for(char it : arguments){
        if(it != ' ' && it != '\n'){
            args[i].push_back(it);
        }
        else{
            i++;
        }
    }
}


void Replace::get_words(const string& str) {
    string got_word;

        for(char it : str){
            if(it != ' ' && it!= '\n'){
                got_word += it;
            }
            else{
                words.push_back(got_word);
                got_word = "";
        }
    }
}


string Replace::replace_words() {
    string str;
    for(auto it : words){
        if (it == word1){
            it = word2;
        }
        str += it;
        str += ' ';
    }
    str += "\n";
    return str;
}


void Replace::parse_args() {
    word1 = args[0];
    word2 = args[1];
}


void Replace::do_work(vector<string> txt) {
    parse_args();
    for(const auto& it : txt){
        get_words(it);
        string rep = replace_words();
        text.push_back(rep);
        words.clear();
    }
}


vector<string> Replace::get_result() {
    return text;
}


Dump::Dump(const string& arguments) {
    for (char i : arguments){
        args[0].push_back(i);
    }
}


void Dump::parse_args() {
    string filename = args[0];
    file.open(filename, ofstream::out);
    if(!file.is_open()) throw FileError();
}


void Dump::do_work(vector<string> txt) {
    parse_args();
    for (const auto& it : txt){
        text.push_back(it);
        file << it;
    }
}


vector<string> Dump::get_result() {
    return text;
}

Count::Count(const string& arguments) {
    args.push_back(arguments);
    amount = 0;
}


void Count::parse_args() {
    word = args[0];
}


void Count::get_words(const string &str) {
    string got_word;

    for(char it : str){
        if(it != ' ' && it!= '\n'){
            got_word += it;
        }
        else{
            words.push_back(got_word);
            got_word = "";
        }
    }
}


void Count::do_work(vector<string> txt) {
    parse_args();
    for (const auto& it : txt){
        get_words(it);
    }
    for (const auto& it : words){
        if (it == word){
            amount++;
        }
    }
}


vector<string> Count::get_result() {
    string s = to_string(amount);
    text.push_back(s);
    return text;
}


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
        worker = IWorker::createWorker(it.first, it.second);
        worker->do_work(text);
        if(it.first != "writefile"){
            text = worker->get_result();
        }
    }
}