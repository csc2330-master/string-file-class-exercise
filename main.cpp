#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::stoi;

int GetSalary(const string& record);
char GetSex(const string& record);

int main() {
    string record = "10001,9/2/53,Georgi,Facello,M,6/26/86,24916";
    int salary = GetSalary(record);
    cout << salary << endl;
    return 0;
}

int GetSalary(const string& record) {
    string salaryText = record.substr(record.find_last_of(',') + 1, record.length());
    return stoi(salaryText);
}
char GetSex(const string& record){

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
