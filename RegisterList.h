#ifndef REGISTERLIST_H
#define REGISTERLIST_H

#include"Registration.h"

class RegisterList:public Registration{
	private:
		struct ListNode{
			string courseName,courseId;
			int courseUnit;
			struct ListNode *next;
		};
		ListNode *head;
	public:
		RegisterList();
		void appendCourse(string courseId,string courseName,int courseUnit);
		int deleteCourse();
		bool searchCourse(string courseName);
		void print();
		int allRegistered(string courseName[]);
		int clear();
		~RegisterList();
};

#endif
