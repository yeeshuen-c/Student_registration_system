#include<string>
#include<iostream>
#include"Registration.h"
using namespace std;

//*****************************************//
//This is a Registration class constructor //
//*****************************************//
Registration::Registration(){}

int Registration::checkAvailability(int currentUnit){
			
	if(currentUnit<15)
		return -1;
	else if(currentUnit>=22)
		return 0;
	else
		return 1;
	
}

//*****************************************************************//
//Check if current units exceed, equal or less than required units //
//*****************************************************************//
bool Registration::courseRegistration(int studentUnit){
	int checkAvailable;	

	char registerMore;
	
	if(studentUnit<15){
		cout<<"Your current units "<<studentUnit<<" is below the minimum required units. You are SUGGESTED to register for MORE courses." << endl;
		return true;
	}
	else if(studentUnit==22){
		cout<<"Your current units "<<studentUnit<<" have reached max units. You CAN'T register for other courses.";
		return false;
	}		
	else if(studentUnit>22){
		cout<<"Your current units "<<studentUnit<<" after registering for this course will exceed the max units. You CAN'T register for this course." << endl;
		return false;
	}
	else{
		cout<<"Your current units is "<<studentUnit<<". You HAVEN'T reach max unit. " << endl;
		return true;
	}
	
	cout<<endl;
	system("pause");
	system("cls");	
}
