#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include<string>
#include<iostream>
#include"Department.h"
using namespace std;
		
class StudentList:public Department{
	private:
		struct ListNode{
			string name,password;
			int matricNo,unit;
			int year,sem;
			double cgpa;
			struct ListNode *next;
		};
		ListNode *head;
		
	public:
		StudentList();
		void appendStudent(string n,string pw,int mNo,int u,int y,int s,float c);
		void printStudentInfo(int val);
		bool searchMatricNo(int val);
		void updateUnit(int val,int u);
		//getter
		string getPassword(int val);
		int getYear(int val);
		int getSem(int val);
		int getUnit(int val);
		float getCgpa(int val);
		string getName(int val);
};

#endif
