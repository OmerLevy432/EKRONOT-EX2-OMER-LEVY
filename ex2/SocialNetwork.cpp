#include <iostream>
#include <string>
#include "SocialNetwork.h"


std::string SocialNetwork::getNetworkName()
{
	return this->networkName;
}

int SocialNetwork::getMinAge()
{
	return this->minAge;
}

std::string SocialNetwork::getWindowsDevices()
{
	// creating a pointer to the linkedlist of profiles
	ProfileNode* current = this->profiles->get_first();

	DevicesList devices;
	std::string devicesString = "";

	// going over each profile
	while (current->get_next())
	{
		devicesString += current->get_data().getOwner().getWindowsDevices();
		devicesString += ", ";
		current = current->get_next();
	}
	devicesString += current->get_data().getOwner().getWindowsDevices();
	
	return devicesString;
}


void SocialNetwork::init(const std::string networkName, const int minAge)
{
	this->networkName = networkName;
	this->minAge = minAge;
	
	// inits the profile linkedlist
	ProfileList profiles;
	profiles.init();
	*this->profiles = profiles;
}

void SocialNetwork::clear()
{
	this->networkName = "";
	this->minAge = 0;
	this->profiles->clear();
	this->profiles = nullptr;
}

bool SocialNetwork::addProfile(const Profile profile_to_add)
{
	// gets the user's age
	unsigned int userAge = profile_to_add.getOwner().getAge();

	// check if the user is old enough
	if (this->minAge > userAge)
	{
		return false;
	}

	// adds the profile
	this->profiles->add(profile_to_add);
}
