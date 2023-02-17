/* 
Programming Project 5: Arrays
Jane McPheron
03/23/2023
*/

 
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;


//class to create objecs out of each data row
class HeightData {       
  public:             // Access specifier
    string myName;        
    string myCity; 
    int myHeight;
};

//declaring vector that will contain all data
vector<HeightData> allData; 

//function for comparing height values
bool compareNum(const HeightData& a, const HeightData& b) {
    return a.myHeight > b.myHeight;
}


//function to organize data
void organizeData(){

ifstream inputFile;

    //accessing the CSV data file
    inputFile.open("people-data.csv");

    //creating a clear line variable
    string line = "";

    //reading csv
    while (getline(inputFile, line)){
        
        //variables to parse out line
        string name;
        string city;
        int height;
        string tempString;

        //creating a string out of the line
        stringstream inputString(line);


        getline(inputString, name, ',');
        getline(inputString, city, ',');
        getline(inputString, tempString, ',');

        //making string value into integer value
        height = atoi(tempString.c_str());

        //placing data into object
        HeightData dataEntry;
        dataEntry.myName = name;
        dataEntry.myCity = city;
        dataEntry.myHeight = height;

        //putting object into a vector
        allData.push_back(dataEntry);

    }

    //sorting the vector
    sort(allData.begin(), allData.end(), compareNum);

}


//function for getting user choice
int getUserChoice(){
    int answer;

    cout << "What would you like to know?" << endl;
    cout << "  1) The tallest person in a city." <<endl <<"  2) The shortest person in a city./n"
    <<"  3) The set of people from a city sorted by height." <<endl
    <<"  4) The tallest person(s) and what cit(ies) they are from."
    << endl << "  0) Quit" <<endl << "" << endl;
    
    cin >> answer;
    return answer;
}


int main(){

    //declaring variable
    int userChoice = 5;

    organizeData();
    userChoice = getUserChoice();
    
    // for(int i = 0; i < allData.size(); i++){
    //     cout << allData[i].myName << allData[i].myCity << allData[i].myHeight << endl;
    // }
    
}