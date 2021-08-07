#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

//class to hold course information
class course {
	public:
		string courseNumber;
		string name;
		string prerequisite1;
		string prerequisite2;
};

//vector of courses decleration
vector<course> courses;




//function to print out a specific course
void courselistsearch() {

	string answer;
	cout << "What course do you want to know about? ";
	cin >> answer;

	for (int i = 0; i < courses.size(); i++) {



		if (courses[i].courseNumber == answer) {

			cout << courses[i].courseNumber << ", " << courses[i].name << endl << "Prerequisites: " << courses[i].prerequisite1 << ", " << courses[i].prerequisite2 << endl << endl;


		}
	}

}
//function to print out courses in alphanumeric order
void courseListAlpha() {

	//predefined function to sort the vector alphanumerically using courseNumber
	sort(courses.begin(), courses.end(), [](course& one, course& two) {return one.courseNumber < two.courseNumber; });

	cout << "Here is a sample schedule: " << endl << endl;
	for (int i = 0; i < courses.size(); i++) {

		cout << courses[i].courseNumber << ", " << courses[i].name << endl;
	}
	cout << endl;
}





//function to read a file line by line, create a new course out of the data and add it to the vector
void LoadData() {
	int commmas;
	string sec1;
	string sec2;
	string sec3;
	string sec4;
	string filename = "ABCU_Advising_Program_Input.txt";
	course tempCourse;

	//code to open and read a file
	string line;
	ifstream myfile(filename);
	if (myfile.is_open())
	{
	
		while (getline(myfile, line))
		{
			//define variables to break up the lines by the delimeter comma
			int sections = 1;
			sec1 = "";
			sec2 = "";
			sec3 = "";
			sec4 = "";



			string str = line;
			char del = ',';
			string temp = "";

			//test for where commas are and break up into the different sections (sec)
			for (int i = 0; i < (int)str.size(); i++) {

				if (str[i] != del) {
					temp += str[i];

				}
				else {

					if (sections == 1) {
						sec1 = temp;
					}
					if (sections == 2) {
						sec2 = temp;
					}
					if (sections == 3) {
						sec3 = temp;
					}
					if (sections == 4) {
						sec4 = temp;
					}



					sections++;
					temp = "";
				}
			}

			if (sections == 1) {
				sec1 = temp;
			}
			if (sections == 2) {
				sec2 = temp;
			}
			if (sections == 3) {
				sec3 = temp;
			}
			if (sections == 4) {
				sec4 = temp;
			}
			//add all fields to a temporary class
			tempCourse.courseNumber = sec1;
			tempCourse.name = sec2;
			tempCourse.prerequisite1 = sec3;
			tempCourse.prerequisite2 = sec4;
			//add temporary class to vector
			courses.push_back(tempCourse);
		}

	}
	//close file
		myfile.close();
}

//function to display menu and run program loop
void showmenu() {
	int run = 0;
	//running loop
	while (run != 9) {
		//menu output for users
	cout << "1. Load Data Structure." << endl << "2. Print Course List" << endl << "3. Print Course." << endl << "9. Exit" << endl << endl;
	cout << "What would you like to do? ";
	cin >> run;

	if (run == 1) {

		//call function to load data
		LoadData();

	}

	else if (run == 2) {

		//call function to print out courses alphanumericaly
		courseListAlpha();

	}

	else if (run == 3) {
		
		//call function to print out a specific course
		courselistsearch();

	}

	else if (run == 9) {
		//ends program
		cout << "Thank you for using the course planner!";
		break;
	}

	else {
		cout << run << " is not a valid option.";
	}
	}




}



//running main
int main(){

	//welcome
	cout << "Welcome to the course planner." << endl << endl;

	//call showmenu function which contains running loop
	showmenu();




}