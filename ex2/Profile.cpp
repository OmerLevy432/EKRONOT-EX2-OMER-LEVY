#include <iostream>
#include <string>
#include "Profile.h"
#include "UserList.h"


void Profile::init(const User& owner)
{
	this->owner = owner;
	
	// inits a page
	Page page;
	page.init();
	this->page = page;

	// inits the friends linkedlist
	UserList friends;
	friends.init();
	this->friendList = friends;
}

void Profile::clear()
{
	this->page.clearPage();
	this->friendList.clear();
	this->owner.clear();
}

void Profile::setStatus(const std::string new_status)
{
	this->page.setStatus(new_status);
}

void Profile::addPostToProfilePage(const std::string post)
{
	this->page.addLineToPosts(post);
}

void Profile::addFriend(const User& friend_to_add)
{
	this->friendList.add(friend_to_add);
}

User Profile::getOwner() const
{
	// copies the user of the owner
	User userCopy;
	userCopy.init(this->owner.getID(), this->owner.getUserName(), this->owner.getAge());


	return userCopy;
}

std::string Profile::getFriends() const
{
	std::string friendsInString = "";
	UserNode* current = this->friendList.get_first(); // sets a pointer to the linkedlist of friends

	// adds all the names of the friends to the string seperating each name with a ','
	while (current->get_next())
	{
		friendsInString += current->get_data().getUserName();
		friendsInString += ",";

		current = current->get_next();
	}

	// adding the final name
	return friendsInString + current->get_data().getUserName();
}

std::string Profile::getPage() const
{
	// gets the status of the user and adds it to the page string, adds the posts aswell
	return "Status: " + this->page.getStatus() + "\n*******************\n*******************" + this->page.getPosts() + "\n";
}

std::string Profile::getFriendsWithSameNameLength() const
{
	// gets the length of the username
	unsigned int nameLength = this->owner.getUserName().length();
	std::string friendsInString = "";
	std::string friendUsername = "";

	// creating a pointer to the head of the friends linkedlist
	UserNode* current = this->friendList.get_first();

	// going over each friend from the friend list
	while (current)
	{
		// gets the name of the friend
		friendUsername = current->get_data().getUserName();

		// checks if the lengthes match
		if (friendUsername.length() == nameLength)
		{
			if (friendsInString != "")
			{
				friendsInString += ",";
			}

			friendsInString += friendUsername;
		}	

		current = current->get_next();
	}
	return friendsInString;
}