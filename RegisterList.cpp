#include<string>
#include<iostream>
#include"RegisterList.h"
using namespace std;

//*****************************************
//This is a RegisterList class constructor 
//*****************************************
RegisterList::RegisterList(){
	head=nullptr;
}

//*****************************************
//This function is to append the course.
//*****************************************
void RegisterList::appendCourse(string courseId,string courseName,int courseUnit){
	ListNode *newNode;
	ListNode *nodePtr;
	
	newNode=new ListNode;
	newNode->courseId=courseId;
	newNode->courseName=courseName;
	newNode->courseUnit=courseUnit;

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

//*****************************************
//This function is for user to delete the 
//registered course
//*****************************************
int RegisterList::deleteCourse(){
	ListNode *nodePtr;
	ListNode *previousNode;
	string courseId;
	int delUnit;			//to store deleted course's unit
	
	cout<<"\tEnter the course ID that you want to remove.\n"
		<<"\tCourse ID: ";
	cin>>courseId;
	
	if(head->courseId!=courseId){
		cout<<"\tYou didn't register for this course."<<endl;
		return 0;
	}
	if(head->courseId==courseId){
		delUnit=head->courseUnit;
		nodePtr=head->next;
		delete head;
		head=nodePtr;
	}
	else{
		nodePtr=head;
		while(nodePtr!=nullptr && nodePtr->courseId!=courseId){
			previousNode=nodePtr;
			nodePtr=nodePtr->next;
		}
		if(nodePtr){
			delUnit=nodePtr->courseUnit;
			previousNode->next=nodePtr->next;
			delete nodePtr;
		}
	}
	return delUnit;
}

//*****************************************
//This function is to search the course Id.
//*****************************************		
bool RegisterList::searchCourse(string courseId){
	ListNode *nodePtr=nullptr;
	nodePtr=head;
	while(nodePtr){
		if(nodePtr->courseId == courseId)
			return true;
		else
			nodePtr=nodePtr->next;
	}
	return false;
}

//**************************************************
//This function is to display the registered course.
//**************************************************	
void RegisterList::print(){
	ListNode *nodePtr=nullptr;
	if(head==nullptr)
		cout<<"\tYou haven't register for any course yet."<<endl;
		
	nodePtr=head;
	while(nodePtr){
		cout << "\t" << nodePtr->courseId << " "<< nodePtr->courseName << " " << nodePtr->courseUnit << endl;
		
		nodePtr=nodePtr->next;
	}
}

//*************************************************
//This function is to search all registered course.
//*************************************************
int RegisterList::allRegistered(string courseName[]){
	ListNode *nodePtr=nullptr;
	nodePtr=head;
	int i=0;
	while(nodePtr){
		courseName[i]=nodePtr->courseId;
		i++;
		nodePtr=nodePtr->next;
	}
	return i;
}

//************************************************
//This function is to remove all registered course
//************************************************	
int RegisterList::clear(){
	int delUnit=0;		//to store deleted courses units
	char confirm;
	cout<<"\tAre you sure to remove all registered courses? (y/Y for yes): ";
	cin>>confirm;
	
	if(confirm=='y'|| confirm=='Y'){
		ListNode *nodePtr;
		ListNode *nextNode;
		nodePtr=head;
		while(nodePtr!=nullptr){
			delUnit+=(nodePtr->courseUnit);
			nextNode=nodePtr->next;
			delete nodePtr;
			nodePtr=nextNode;
			head=nullptr;
		}
	}
	else
		return 0;
		
	return delUnit;
}

//*****************************************
//This is a RegisterList class destructor 
//*****************************************
RegisterList::~RegisterList(){
	ListNode *nodePtr;
	ListNode *nextNode;
	nodePtr=head;
	while(nodePtr!=nullptr){
		nextNode=nodePtr->next;
		delete nodePtr;
		nodePtr=nextNode;
	}
}
