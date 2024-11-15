#pragma once
#include <string>
#include "DeviceList.h"


class User
{
private:
	unsigned int id;
	std::string username;
	unsigned int age;
	DevicesList* devices;

public:
	// methods that don't change the artibutes of the object
	unsigned int getID() const;
	std::string getUserName() const;
	std::string getWindowsDevices() const;
	unsigned int getAge() const;
	DevicesList& getDevices() const;
	bool checkIfDevicesAreOn() const;
	
	// methods that change the artibutes of the object
	void init(const unsigned int id, const std::string username, const unsigned int age);
	void clear();
	void addDevice(const Device newDevice);
};

