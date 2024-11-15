#pragma once 
#include <iostream>
#include <string>
#include "ProfileList.h"


class SocialNetwork
{
private:
	std::string networkName;
	int minAge;
	ProfileList profiles;

public:
	// methods that don't change the artibutes of the object
	std::string getNetworkName();
	int getMinAge();
	std::string getWindowsDevices();

	// methods that change the artibutes of the object
	void init(const std::string networkName, const int minAge);
	void clear();
	bool addProfile(const Profile& profile_to_add);
};

