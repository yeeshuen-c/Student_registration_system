#include<string>
#include<iostream>
#include<fstream>
#include<iomanip>
#include<stdio.h>
#include<stdlib.h>
#include"StudentList.h"
#include"Department.h"
#include"Course.h"
#include"Registration.h"
#include"RegisterList.h"
using namespace std;

int main(){
	
	StudentList stuList;
	RegisterList reList;
	string password;
	int matricNo,unit;
	fstream fobj;								//file object to read student list from file
	fobj.open("studentList2.txt",ios::in);
	int i=0;									//counter for student list
	bool check=false,check2=false;				//bool variable to use for checking
	string major="none";
	string cId,cName;							//variable needed for course registration
	int stuUnit,cUnit,numRegistered,deleteUnit; 
	int option;
	bool successRegister=false,courseRe=false;  
	char registerMore;						
	
	stuList.displayWelcome();
	
	while(fobj && i<10){
		string name,password;
		int matricNo,unit;
		int year,sem;
		float cgpa;
		
		getline(fobj,name,'\t');
		getline(fobj,password,'\t');
		fobj>>matricNo;
		fobj>>year;
		fobj>>sem;
		fobj>>unit;
		fobj>>cgpa;
		i++;
		
		stuList.appendStudent(name,password,matricNo,unit,year,sem,cgpa);
	}
	fobj.close();	//close file after read

//Log in students by matric number
	cout << endl;
	cout << "\t\t\t\t ________________________ LOG IN _______________________\n\n";
	cout << "\t\t\t\t|\tPlease enter you matric number and password.\t|\n";
	cout << "\t\t\t\t|\t\t\t\t\t\t\t|\n";
	cout << "\t\t\t\t \tMatric Number	: "; 
	cin >> matricNo; 
	
	if((stuList.searchMatricNo(matricNo))){
		check=true;
	}
	else
		check=false;
	
	if(!check){
		cout << "\t\t\t\t ___________________________________________________\n\n";
		cout << "\t\t\t\tYour name is not on the student list." << endl;
		cout << "\t\t\t\tPlease register your self before access to this registration system."<< endl;
		cout << "\t\t\t\tNow exiting the program..." << endl;
		abort();	//this function is used to exit the program
	}
	//Check password to login
		do{
			cout << "\t\t\t\t \tPassword	: "; 
			cin>>password;
			cout << "\t\t\t\t|\t\t\t\t\t\t\t|\n";
			cout << "\t\t\t\t|_______________________________________________________|\n\n";
			cout << "\t\t\t      *************************************************************\n";
			cout << "\t\t\t\t\t\t\t Loading...\n";
			cout << "\t\t\t      *************************************************************\n\n";
		
			for(int i=0;i<10;i++){
				if((stuList.searchMatricNo(matricNo))){
					if(password==(stuList.getPassword(matricNo)))
						check2=true;
				}
			}
			if(check2==false){
				cout << "\t\t\t\t\tWrong password! Please enter again." << endl << endl;
			}
			
		}while(check2==false);
		
		if(check2)
			stuList.printStudentInfo(matricNo);
			
	//main menu
	system("pause");
	system("cls");
	stuList.initializeCoreCourses();
	stuList.initializeMajor();
	stuList.initializeOpenCourses();
	

	do{ 
	cout<<"\tRegistered Course: "<<endl;
	reList.print();
		cout << endl;
		cout << "\tEnter the number based on the option selected. (1~6)" << endl;
		cout << "\n\t\t\t___________________________________________________________________________\n";
   		cout << "\n\t\t\t******************************** Main Menu ********************************\n";
   		cout << "\t\t\t___________________________________________________________________________\n\n";	
		cout << "\t\t\t|                                                                         |\n";
		cout << "\t\t\t|\tOption 1: Display ALL courses in CS School.                       |\n";
		cout << "\t\t\t|\tOption 2: REGISTER for courses / REGISTER for MORE courses.       |\n";
		cout << "\t\t\t|\tOption 3: REMOVE registration for ONE course.                     |\n";
		cout << "\t\t\t|\tOption 4: REMOVE registration for ALL courses.                    |\n";
		cout << "\t\t\t|\tOption 5: Display your student information.                       |\n";
		cout << "\t\t\t|\tOption 6: END registration process, EXIT system.                  |\n";
		cout << "\t\t\t|                                                                         |\n";
		cout << "\t\t\t|_________________________________________________________________________|\n\n";

		cout << "\tEnter your option : ";
		cin >> option;

		switch(option){
			case 1: stuList.displayAllCourses(); break;
			case 2: registerMore='y'; break;
			case 3: deleteUnit=reList.deleteCourse(); break;
			case 4: deleteUnit=reList.clear(); break;
			case 5: stuList.printStudentInfo(matricNo); break;
			case 6: break;
			default: cout << "\tInvalid option. Please enter again.\n\n"; break; 
		}

		
		if(registerMore=='y'){
			system("cls");
			cout<<"\tThe following are core courses(T) available for you to register at the current moment:"<<endl;
			stuList.printCoreCourses((stuList.getYear(matricNo)),(stuList.getSem(matricNo)));
			//major courses
			if((stuList.getYear(matricNo)>1) && (stuList.getSem(matricNo)>=1) && major=="none"){
			do{		//continue looping if entered invalid major
				cout<<endl;
				cout << "\t\t\t\t ________________________Reminder_______________________\n";
				cout << "\t\t\t\t|\t                                                |\n";
				cout << "\t\t\t\t|\tCPC	: Intelligent Computing                 |\n";
				cout << "\t\t\t\t|\tCSE	: Software Engineering                  |\n";
				cout << "\t\t\t\t|\tCST	: Computing Infrastructure              |\n";
				cout << "\t\t\t\t|_______________________________________________________|\n\n";
				cout << "\t\t\t     **************************************************************";
				cout << "\n\t\t\t    Please enter what major you are in (CPC/CSE/CST): ";
				cin >> major;
				cout << "\t\t\t     **************************************************************\n";
		
			}while((major!="CPC") && (major!="CSE") && (major!="CST"));
		
			cout<<endl;
			cout<<"\tThe following are major courses(M) available for you to register at the current moment:"<<endl;
			}
			stuList.printMajorCourses((stuList.getYear(matricNo)),(stuList.getSem(matricNo)),major);
			
			cout<<"\tThe following are open courses(U) available for you to register at the current moment:"<<endl;
			stuList.printOpenCourses();
			stuList.registerCourse(cId,cName,cUnit,stuUnit,numRegistered,(stuList.getUnit(matricNo)));
			successRegister=reList.courseRegistration(stuUnit);
			if(successRegister){									//append registered courses to linked list
				courseRe=reList.searchCourse(cId);
				if(!courseRe){
					reList.appendCourse(cId,cName,cUnit);
					stuList.updateUnit(matricNo,stuUnit);			//update student's unit after register
				}
				else
					cout<<"\n\n!! This course is already REGISTERED. Please register for other courses. !!\n"<<endl;
			}
			registerMore='z';
		}
		if(deleteUnit>0){
			stuUnit=(stuList.getUnit(matricNo))-deleteUnit;		//minus deleted course's unit
			stuList.updateUnit(matricNo,stuUnit);				//update student's unit after remove course
			deleteUnit=0;
		}
		system("pause");
		system("cls");	
	}while(option!=6);
	
	//Display final page	
   	cout << "\n****************************************************** Final Page ******************************************************\n";
	stuList.printStudentInfo(matricNo);

	cout << "\n\tRegistered Courses : \n" << endl;
	reList.print(); 
    cout << "________________________________________________________________________________________________________________________\n\n\n";
    cout << "\t\t\t\t\tYou have completed your registration."
		 <<	"\n\t\t\t\t\t\tNow exiting the system...\n"; 
 
 
 	//Write to text file to record
	fobj.open("recordRegister.txt",ios::out);
	int tempMatricNo = 11111;
	string courseName[5];		//uses dynamic array
	int n;
	for(int i=0;i<10;i++){
		fobj<<(stuList.getName(tempMatricNo))<<"\t"<<(stuList.getPassword(tempMatricNo))<<"\t"<<tempMatricNo<<"\t"<<(stuList.getYear(tempMatricNo))<<"\t";
		fobj<<(stuList.getSem(tempMatricNo))<<"\t"<<(stuList.getCgpa(tempMatricNo));
		
		if(tempMatricNo==matricNo){
			n=reList.allRegistered(courseName);
			for(int i=0;i<n;i++){
				fobj<<"\t"<<courseName[i];
			}
		}
		fobj << endl;
		tempMatricNo++;
	}
	fobj.close();
	
	return 0;
}
