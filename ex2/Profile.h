#pragma once
#include <string>
#include "User.h"
#include "UserList.h"
#include "Page.h"


class Profile
{
private:
	User* owner;
	Page* page;
	UserList* friendList;

public:
	// methods that don't change the artibutes of the object
	User getOwner() const;
	std::string getPage() const;
	std::string getFriends() const;
	std::string getFriendsWithSameNameLength() const;

	// methods that change the artibutes of the object
	void init(User owner);
	void clear();
	void setStatus(std::string new_status);
	void addPostToProfilePage(std::string post);
	void addFriend(User friend_to_add);

};