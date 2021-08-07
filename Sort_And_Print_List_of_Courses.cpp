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
