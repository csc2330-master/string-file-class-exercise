#include <iostream>
#include <string>
#include <fstream>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::stoi;

using std::ifstream;

int GetSalary(const string& record);
char GetSex(const string& record);

int main() {
    string record, filename;
    cout << "Filename: ";
    cin >> filename;
    ifstream file(filename);
    if (!file.is_open()){
        cerr << "Error opening file " << filename << endl;
        return 1;
    }
    int recordCount = 0;
    while (getline(file, record)){
        cout << record << endl;
        recordCount++;
    }
    cout << recordCount << " read" << endl << endl;
    file.close();
    return 0;
}

int GetSalary(const string& record) {
    string salaryText = record.substr(record.find_last_of(',') + 1, record.length());
    return stoi(salaryText);
}
char GetSex(const string& record){
    size_t start = 0, position = record.find(',');
    char sex;
    for (int i = 0; i < 3 && position != string::npos; ++i) {
        start = position + 1;
        position = record.find(',', start);

    }
    if (record[position + 1] == 'M')
        sex = 'm';
    else
        sex = 'f';
    return sex;
}

//size_t position = record.find(',');
//size_t start = 0;
//if (position != string::npos)
//cout << record.substr(start, position - start)<<endl;
//while (position != string::npos){
//start = position + 1;
//position = record.find(',', start);
//cout << record.substr(start, position - start)<<endl;
//}
