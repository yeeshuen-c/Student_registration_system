#include<iostream>
#include<fstream>
#include<iomanip>
#include"StudentList.h"
#include"Department.h"
using namespace std;

//*****************************************//
//This is a StudentList class constructor //
//*****************************************//
StudentList::StudentList(){
	head=nullptr;
}

//*****************************************//
//This function is to append students into //
//linked list                
//*****************************************//
void StudentList::appendStudent(string n,string pw,int mNo,int u,int y,int s,float c){
	ListNode *newNode;
	ListNode *nodePtr;
	
	newNode=new ListNode;
	newNode->name=n;
	newNode->password=pw;
	newNode->matricNo=mNo;
	newNode->unit=u;
	newNode->year=y;
	newNode->sem=s;
	newNode->cgpa=c;
	newNode->next=nullptr;
	
	if(!head){
		head=newNode;
	}
	else{
		nodePtr=head;
		while(nodePtr->next)
			nodePtr=nodePtr->next;
		nodePtr->next=newNode;
	}
}

//*****************************************//
//This function is to print all students info
//*****************************************//
void StudentList::printStudentInfo(int val){
	ListNode *nodePtr=nullptr;
	nodePtr=head;
	
	while(nodePtr){
		if(nodePtr->matricNo == val){
			cout<< "________________________________________________________________________________________________________________________\n\n" 
				<< setw(16) << "Name" << setw(20) << "Matric Number" << setw(20) << "Current Units" << setw(20) << "Study Year" << setw(20) << "Semester" << setw(20) 
				<< "CGPA"<<"\n" 
				<< "________________________________________________________________________________________________________________________\n\n" 
				<< setw(16) << nodePtr->name << setw(20) << nodePtr->matricNo << setw(20) << nodePtr->unit << setw(20) << nodePtr->year << setw(20) << nodePtr->sem 
				<< setw(20) 
				<< nodePtr->cgpa << setw(20) 
				<< "\n\n________________________________________________________________________________________________________________________" << endl << endl;
		return;
		}
		else{
			nodePtr=nodePtr->next;
		}
	}
}

//*****************************************//
//This function is to search student's matric no
//*****************************************//
bool StudentList::searchMatricNo(int val){
	ListNode *nodePtr=nullptr;
	nodePtr=head;
	
	while(nodePtr){
		if(nodePtr->matricNo == val){
			return true;
		}
		else{
			nodePtr=nodePtr->next;
		}
	}

	return false;
}

//*****************************************//
//This function is to update student's unit
//*****************************************//
void StudentList::updateUnit(int val,int u){
	ListNode *nodePtr=nullptr;
	nodePtr=head;
	
	while(nodePtr){
		if(nodePtr->matricNo == val){
			nodePtr->unit=u;
			return;
		}
		else{
			nodePtr=nodePtr->next;
		}
	}
}

//*****************************************//
//This function is to get student's password
//*****************************************//
string StudentList::getPassword(int val){
	ListNode *nodePtr=nullptr;
	nodePtr=head;
	
	while(nodePtr){
		if(nodePtr->matricNo == val){
			return (nodePtr->password);
		}
		else{
			nodePtr=nodePtr->next;
		}
	}

	return "0";
}

//*****************************************//
//This function is to get student's year
//*****************************************//
int StudentList::getYear(int val){
	ListNode *nodePtr=nullptr;
	nodePtr=head;
	
	while(nodePtr){
		if(nodePtr->matricNo == val){
			return (nodePtr->year);
		}
		else{
			nodePtr=nodePtr->next;
		}
	}
}

//*****************************************//
//This function is to get student's sem
//*****************************************//
int StudentList::getSem(int val){
	ListNode *nodePtr=nullptr;
	nodePtr=head;
	
	while(nodePtr){
		if(nodePtr->matricNo == val){
			return (nodePtr->sem);
		}
		else{
			nodePtr=nodePtr->next;
		}
	}
}

//*****************************************//
//This function is to get student's unit
//*****************************************//
int StudentList::getUnit(int val){
	ListNode *nodePtr=nullptr;
	nodePtr=head;
	
	while(nodePtr){
		if(nodePtr->matricNo == val){
			return (nodePtr->unit);
		}
		else{
			nodePtr=nodePtr->next;
		}
	}
}

//*****************************************//
//This function is to get student's cgpa
//*****************************************//
float StudentList::getCgpa(int val){
	ListNode *nodePtr=nullptr;
	nodePtr=head;
	
	while(nodePtr){
		if(nodePtr->matricNo == val){
			return (nodePtr->cgpa);
		}
		else{
			nodePtr=nodePtr->next;
		}
	}
}

//*****************************************//
//This function is to get student's name
//*****************************************//
string StudentList::getName(int val){
	ListNode *nodePtr=nullptr;
	nodePtr=head;
	
	while(nodePtr){
		if(nodePtr->matricNo == val){
			return (nodePtr->name);
		}
		else{
			nodePtr=nodePtr->next;
		}
	}
}
