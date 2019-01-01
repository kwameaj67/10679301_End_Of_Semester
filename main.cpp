#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <windows.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int chooseFromMenu();
bool request(string message);
struct Course {
	string CourseName;
	int CourseID;
	int numberOfStudents = 0;
	char Grade;
};
struct Student {
	int StudentID;
	string StudentFirstName;
	string StudentLastName;
	int NumberofCourses;
	vector<Course> Courses;
};



	vector<Student> Students;
	vector<Course> Courses;

int CourseMenu(){
	Sleep(1000);
	cout << endl;
	cout << "\tCourse Menu"<<endl;
	cout << "1. Add Course"<<endl;
	cout << "2. Delete Course"<< endl;
	cout << "3. Course Details" << endl;
	cout << "0. Back"<<endl;

	return chooseFromMenu();
}


string getGrade(int score){

	if(score >=80 && score <= 100){
		return "A";
	}else if (score >=75 && score <80){
		return "B+";
	}else if (score >=70 && score <75){
		return "B";
	}else if (score >=65 && score <70){
		return "C+";
	}else if (score >=60 && score <65){
		return "C";
	}else if (score >=55 && score  < 60){
		return "D+";
	}else if (score >= 50 && score <55){
		return "D";
	}else if (score >= 45 && score <50){
		return "E";
	}else return "F";
}

void sortStudents(){
	for(int i=0; i<Students.size(); i++){
		for(int k=0; k<Students.size()-1; k++){
			if(Students[k].StudentID > Students[k+1].StudentID){
				Students[k].StudentID ^= Students[k+1].StudentID;
				Students[k+1].StudentID ^= Students[k].StudentID;
				Students[k].StudentID ^= Students[k+1].StudentID;
			}
		}
	}
}

int searchStudent(int StudentsID){
	int index = -1;
		Sleep(1000);
	for(int i=0; i<Students.size(); i++)
	{
		if(Students[i].StudentID == StudentsID){
			index = i;
		}
	}

	return index;

}

int searchCourse(int CourseCode){
		int index = -1;
		Sleep(1000);
	for(int i=0; i<Courses.size(); i++)
	{
		if(Courses[i].CourseID== CourseCode){
			index = i;
		}
	}

	return index;
}
int showStudentMenu(){
	Sleep(1000);
	cout << endl;
	cout << "\tStudent\n";
	cout << "1. Add Student\n";
	cout << "2. Edit Student\n";
	cout << "3. Search Student\n";
	cout << "4. Delete Student\n";
	cout << "5. View All Students\n";
	cout << "6. Register a Course\n";
	cout << "7. Add Student Grade\n";
	cout << "8. Print Academic Record\n";
	cout << "0. Go Back\n";

	return chooseFromMenu();
}

void editStudent(){

	cout << "Enter Student's ID: ";
	int Id;
	cin >> Id;
		Sleep(1000);
	int Index = searchStudent(Id);
	if(Index != -1){

		cout << endl;
		cout << "Edit Student's Profile";
		cout << "Student's ID = " << Students[Index].StudentID << "\nStudent's Name = " << Students[Index].StudentLastName << " " << Students[Index].StudentFirstName << endl;
		if(request("Do you want Edit Students' Details? (Yes/No)'")){
			cout << "Enter First Name: ";
			string FirstName;
			string LastName;

			start:
					Sleep(1000);
			cout << "Enter First Name: " ;
			cin >> FirstName;
			cout <<"Enter Last Name: ";
			cin >> LastName;
			while(FirstName.length() == 0 || LastName.length() == 0){
				cout << "Incorrect Input, Fields can't be Empty";
				goto start;
			}

			Students[Index].StudentFirstName = FirstName;
			Students[Index].StudentLastName = LastName;

		}



	}else {
		cout << "Student " << Id << " can't be found in record." << endl;
	}


}

void SearchandRetrieveStudent(){
		cout << "Enter Student's ID: ";
	int Id;
	cin >> Id;
		Sleep(1000);

	int Index = searchStudent(Id);
	if(Index != -1){
		cout << endl;
		cout << "Edit Student's Profile";
		cout << "Student's ID = " << Students[Index].StudentID << "\nStudent's Name = " << Students[Index].StudentLastName << " " << Students[Index].StudentFirstName << endl;
    }else {
    	cout << "Student can't be found in Record" << endl;
	}
}
void addStudent(){

	Student student;

	cout << "Enter Student's First Name: ";
	cin >> student.StudentFirstName;
	cout << "Enter Student's Last Name: ";
	cin  >> student.StudentLastName;
	student.NumberofCourses = 0;
	cout << "Enter Student's ID: ";
	cin >> student.StudentID;
		Sleep(1000);
	Students.push_back(student);
	cout << "... Student Added Successfully"<<endl;
	cout << "Total number of students is : " << Students.size() << endl;

}

void RemoveStudent(){
	int Id;
	cout << "Please enter Student's ID: ";
	cin >> Id;
		Sleep(1000);
	int Index = searchStudent(Id);
	if(Index != -1){
		if(request("Do you want to remove Student? ")){
			Students.erase(Students.begin()+Index);
			cout << "Student " << Id << " has been removed successfully...";
		}
	}else {
		cout << "Student can't be found in record"<<endl;
	}
}

void showAllStudents(){
		Sleep(1000);
	if(Students.size() != 0){
			cout << endl;
	cout << "\tStudent's Database"<< endl;
	cout << "Index\tFirstName\tLastName\tIndex Number\tNo Of Courses Registered"<<endl;
	for(int i=0; i<Students.size(); i++){
		cout << i << "\t"<<Students[i].StudentFirstName << "\t\t"  <<  Students[i].StudentLastName << "\t\t"  << Students[i].StudentID << "\t\t" <<  Students[i].Courses.size() << endl;
	 }
	}else cout << "No student registered" << endl;

}

void DeleteCourse(){
		int Id;
	cout << "Please enter Course Code:  ";
	cin >> Id;
		Sleep(1000);
	int Index = searchCourse(Id);
	if(Index != -1){
		if(request("Do you want to remove Course ")){
			Courses.erase(Courses.begin()+Index);
			cout << "Course " << Id << " has been removed successfully...";
		}
	}else {
		cout << "Course can't be found in record"<<endl;
	}
}

void showCourseDetails(){
	cout << "Please enter Course Code:  ";
	int Id;
	cin >> Id;
		Sleep(1000);
	int Index = searchCourse(Id);
	if(Index != -1){
			cout << "Course Name: " << Courses[Index].CourseName<<endl;
			cout << "Course Code: " << Courses[Index].CourseID<<endl;
			cout << "Number of Students Registered: " << Courses[Index].numberOfStudents;
	}else {
		cout << "Course can't be found in record"<<endl;
	}
}

void AddCourse(){
	Sleep(1000);
		Course course;

	cout << "Enter Course Name: ";
	cin >> course.CourseName;
	cout << "Enter Course ID: ";
	cin >> course.CourseID;

	Courses.push_back(course);
	Sleep(1000);
	cout << "Course Added Successfully..." << endl;
}

void selectFromCourseList(){
	start:
		switch(CourseMenu()){
			case 0:
					Sleep(1000);
				break;
			case 1:
				cout << endl;
				cout << "Add Course" << endl;
				AddCourse();

				goto start;
				break;
			case 2:

				DeleteCourse();
				goto start;
				break;
			case 3:

				showCourseDetails();
				goto start;
				break;
		}
}

void RegisterStudentCourse(){
	cout << "Enter Student's Id: ";
	int StudentID;
	cin >> StudentID;
	cout << "Enter Course ID: ";
	int CourseId;
	cin >> CourseId;
	int sIndex = searchStudent(StudentID);
	int cIndex = searchCourse(CourseId);
	if(sIndex != -1){
		if(cIndex != -1){
			if(request("Do you want to register this course? ")){
				Students[sIndex].Courses.push_back(Courses[cIndex]);
				cout << "Course Added Successfully ..."<< endl;
			}
		}else {
				cout << "Can't find Course..." << endl;
			}
		}else {
			cout << "Can't find Student in Record"<< endl;
 		 }
	}

void selectFromStudentList(){
	start:
		switch(showStudentMenu()){
			case 0:
					Sleep(1000);
				break;
			case 1:
				cout << endl;
				cout << "Add Student" << endl;
				addStudent();

				goto start;
				break;
			case 2:

				editStudent();
				goto start;
				break;
			case 3:

				SearchandRetrieveStudent();
				goto start;
				break;
			case 4:
				RemoveStudent();
				goto start;
				break;
			case 5:

				showAllStudents();
				goto start;
				break;
			case 6:
				RegisterStudentCourse();
				goto start;
				break;
			case 7:

			break;
		}
}

int showMenu(){
	cout << "\tStudents Management System\n";
	cout << "*******************************************\n";
	cout << "* 1. Student Menu (Add, Edit, Search, ... *\n";
	cout << "* 2. Courses Menu (Add, Delete, ... *\n";
	cout << "* 3. Staff Menu(Add, Edit, Delete, ...    *\n";
	cout << "* 0. Exit  							   *\n";
	cout << "*******************************************"<<endl;
	return chooseFromMenu();
}

int chooseFromMenu(){
	cout << endl;
	cout << "Choose from Menu: ";
	int input;
	cin >> input;
	return input;
}



bool request(string message){
	cout << message << " Yes/No ";
	string input;
	cin >> input;
	if(input== "Yes" || input == "Y" || input == "yes" || input == "y"){
		return true;
	}else if (input== "No" || input == "N" || input == "no" || input == "n"){
		return false;
	}else {
		cout << "Invalid Input !!" << endl;
		request(message);
	}
}


int main(int argc, char** argv) {


start:
	switch(showMenu()){
		case 1:
		selectFromStudentList();
		goto start;
		break;
		case 2:
		selectFromCourseList();
		goto start;
		break;
		case 3:

		goto start;
		break;

		case 0:

				Sleep(1000);
				cout << "\nThanks for using this Application.";
				return 0;

	}

	return 0;
}
