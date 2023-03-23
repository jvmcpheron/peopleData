/* 
Programming Project 6: Classes
Jane McPheron
03/30/2023
*/

  
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

//FUNCTIONS FOR ORGANIZING AND WORKING WITH DATA
//class to create objecs out of each data row
class HeightData {       
  public:             // Access specifier
    string myName;        
    string myCity; 
    int myHeight;
};

//function for comparing height values
bool compareNum(const HeightData& a, const HeightData& b);

//function to organize data
vector<HeightData> organizeData();


//FUNCTIONS FOR USER OPTIONS
//function for getting user choice
int getUserChoice();

//function for giving information on the tallest person in a city
void tallestInCity(vector<HeightData> allData);

//function for giving information on the tallest person in a city
void shortestInCity(vector<HeightData> allData);

//function for giving info on all people in the city
void allPeopleInCity(vector<HeightData> allData);

//function for giving information on the tallest person/people overall
void tallestPeople(vector<HeightData> allData);



int main(){

    //declaring variable
    int userChoice = 5;

    //organizing data into a sorted list of objects
    vector<HeightData> allData;

    allData = organizeData();

    //looping through what the user wants
    while (userChoice != 0){
        userChoice = getUserChoice();
        if (userChoice == 1){
            tallestInCity(allData);
        } else if (userChoice == 2){
            shortestInCity(allData);
        }else if (userChoice == 3){
            allPeopleInCity(allData);
        }else if (userChoice == 4){
            tallestPeople(allData);
        }else if (userChoice == 0){
            cout << "Good bye!";
        }else{
            cout << "Sorry, I don't understand" << endl;
        }
    }
    
    
    // for(int i = 0; i < allData.size(); i++){
    //     cout << allData[i].myName << allData[i].myCity << allData[i].myHeight << endl;
    // }
    
}

bool compareNum(const HeightData& a, const HeightData& b) {
    return a.myHeight > b.myHeight;
}

vector<HeightData> organizeData(){

    ifstream inputFile;


    //declaring vector
    vector<HeightData> mainData;

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
        mainData.push_back(dataEntry);

    }

    //sorting the vector
    sort(mainData.begin(), mainData.end(), compareNum);

    return mainData;

}

int getUserChoice(){
    int answer;

    cout << "What would you like to know?" << endl;
    cout << "  1) The tallest person in a city." <<endl 
    <<"  2) The shortest person in a city." <<endl
    <<"  3) The set of people from a city sorted by height." <<endl
    <<"  4) The tallest person(s) and what cit(ies) they are from."
    << endl << "  0) Quit" <<endl << "" << endl;
    
    cin >> answer;
    return answer;
}

void tallestInCity(vector<HeightData> allData){

    //getting user input for search
    string search;
    bool success = false;
    cout << "What city would you like to know about?";
    cin >> search;


    for(int i = 0; i < allData.size(); i++) {
        if (allData[i].myCity == search){
            cout << endl;
            cout<< "The tallest person in " << allData[i].myCity << " is " 
            << allData[i].myName << " at " << allData[i].myHeight << " inches." << endl;
            cout << endl <<endl <<endl;

            //telling computer that the search was successful
            success = true;
            break;
        }
    }
        //telling user computer did not find their search
    if (success == false){
        cout << endl;
        cout << "Sorry, that information is unavailable." << endl;
        cout << endl <<endl <<endl;
    }
}

void shortestInCity(vector<HeightData> allData){

//getting user input for search
    string search;
    bool success = false;
    cout << "What city would you like to know about?";
    cin >> search;


    for(int i = allData.size(); i > -1; i--) {
        if (allData[i].myCity == search){
            cout << endl;
            cout<< "The shortest person in " << allData[i].myCity << " is " 
            << allData[i].myName << " at " << allData[i].myHeight << " inches." << endl;
            cout << endl <<endl <<endl;

            //telling computer that the search was successful
            success = true;
            break;
        }
    }
        //telling user computer did not find their search
    if (success == false){
        cout << endl;
        cout << "Sorry, that information is unavailable." << endl;
        cout << endl <<endl <<endl;
    }
}

void allPeopleInCity(vector<HeightData> allData){

    //taking user input for search
    string search;
    cout << "What city would you like to know about?";
    cin >> search;

    //starting output of information
    cout <<endl;
    cout << "People from " << search << ":" <<endl;
    cout << "Name         Height" <<endl;
    cout << "-------------------" << endl;

    //looping through list
    for(int i = allData.size(); i > -1; i--) {
        if (allData[i].myCity == search){
            cout<< allData[i].myName << " " << allData[i].myHeight << endl;
        }

    }
    cout <<endl << endl <<endl;

}

void tallestPeople(vector<HeightData> allData){

    cout << "The tallest people at " << allData[0].myHeight <<" inches is/are: " << endl;
    for(int i = 0; i < allData.size(); i++) {
        if (allData[i].myHeight == allData[0].myHeight){
            cout << allData[i].myName << " from " << allData[i].myCity << endl;
            
        }
    }
    cout  <<endl<<endl;
}


