#include<string>
#include<iostream>
#include"Course.h"
using namespace std;

//*****************************************//
//This is a Course class constructor       //
//*****************************************//
Course::Course(){}

//setter
//*****************************************//
//This function is to set course's id
//*****************************************//
void Course::setCourseId(string cid){
	courseId=cid;
}

//*****************************************//
//This function is to set course's name
//*****************************************//
void Course::setCourseName(string cn){
	courseName=cn;
}

//*****************************************//
//This function is to set course's type
//*****************************************//
void Course::setCourseType(char ct){
	courseType=ct;
}

//*****************************************//
//This function is to set course's unit
//*****************************************//
void Course::setCourseUnit(int cu){
	courseUnit=cu;
}

//getter
//*****************************************//
//This function is to get course's id
//*****************************************//	
string Course::getCourseId(){
	return courseId;
}

//*****************************************//
//This function is to get course's name
//*****************************************//
string Course::getCourseName(){
	return courseName;
}

//*****************************************//
//This function is to get course's type
//*****************************************//
char Course::getCourseType(){
	return courseType;
}

//*****************************************//
//This function is to get course's unit
//*****************************************//
int Course::getCourseUnit(){
	return courseUnit;
}

//*****************************************//
//This is operator overloading function to 
//print out course's details
//*****************************************//
ostream &operator<<(ostream &os,const Course cobj){
	os<<cobj.courseId<<"\t"<<cobj.courseName<<"\t"<<cobj.courseType<<"\t"<<cobj.courseUnit;
	return os;
}
