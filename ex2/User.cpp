#include <iostream>
#include <string>
#include "User.h"


unsigned int User::getID() const
{
	return this->id;
}
std::string User::getUserName() const
{
	return this->username;
}
unsigned int User::getAge() const
{
	return this->age;
}
DevicesList& User::getDevices() const
{
	return *this->devices;
}
bool User::checkIfDevicesAreOn() const
{
	// get a pointer to the head of the devices linkedlist
	DevicesList* current = this->devices;

	while (current->get_first())
	{
		// checking if the device is not active
		if (!current->get_first()->get_data().isActive())
		{
			return false;
		}
		current->set_first(current->get_first()->get_next());
	}

	return true;
}

void User::init(const unsigned int id, const std::string username, const unsigned int age)
{
	this->id = id;
	this->username = username;
	this->age = age;
}

void User::clear()
{
	// resets the given values of the object
	this->id = 0;
	this->username = "";
	this->age = 0;

	// resets the linkedlist of devices
	this->devices->clear();
	this->devices = nullptr;
}