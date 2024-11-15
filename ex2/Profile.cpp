#include <iostream>
#include <string>
#include "Profile.h"
#include "UserList.h"


User Profile::getOwner() const
{
	// copies the user of the owner
	User userCopy;
	userCopy.init(this->owner->getID(), this->owner->getUserName(), this->owner->getAge());

	return userCopy;
}

void Profile::init(User owner)
{
	*this->owner = owner;
}

std::string Profile::getFriends() const
{
	std::string friendsInString = "";
	UserList* current = this->friendList; // sets a pointer to the linkedlist of friends

	while (current->get_first()->get_next())
	{
		friendsInString += current->get_first()->get_data().getUserName();
		friendsInString += ",";
	}
	return friendsInString + current->get_first()->get_data().getUserName();
}