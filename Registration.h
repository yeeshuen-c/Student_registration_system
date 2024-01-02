#ifndef REGISTRATION_H
#define REGISTRATION_H

#include"Course.h"

class Registration{
	private:
		int date;
		int currentUnit;
	public:
		Registration();
		int checkAvailability(int currentUnit);
		bool courseRegistration(int studentUnit);
};

#endif
