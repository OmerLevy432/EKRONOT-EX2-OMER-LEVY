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
	DeviceNode* current = this->devices->get_first();

	while (current)
	{
		// checking if the device is not active
		if (!current->get_data().isActive())
		{
			return false;
		}
		current = current->get_next();
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

void User::addDevice(const Device newDevice)
{
	this->devices->add(newDevice);
}

std::string User::getWindowsDevices() const
{
	// set a pointer to the linkedlist of devices
	DeviceNode* current = this->devices->get_first();
	Device currentDevice;
	std::string devicesString = "";

	// going over each device
	while (current->get_next())
	{
		currentDevice = current->get_data();

		// check if the device uses windows
		if (currentDevice.isWindows())
		{
			devicesString = devicesString + "[" + std::to_string(currentDevice.getID()) + ", " + currentDevice.getOS() + "], ";
		}

		current = current->get_next();
	}
	currentDevice = current->get_data();

	// check if the device uses windows
	if (currentDevice.isWindows())
	{
		devicesString = devicesString + "[" + std::to_string(currentDevice.getID()) + ", " + currentDevice.getOS() + "], ";
	}

	return devicesString;
}