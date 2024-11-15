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
	void init(const User owner);
	void clear();
	void setStatus(const std::string new_status);
	void addPostToProfilePage(const std::string post);
	void addFriend(const User friend_to_add);

};