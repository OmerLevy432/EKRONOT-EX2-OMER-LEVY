#pragma once


class Page
{
private:
	std::string status;
	std::string posts;

public:
	// methods that don't change the artibutes of the object
	std::string getPosts() const;
	std::string getStatus() const;

	// methods that change the artibutes of the object
	void init();
	void clearPage();
	void setStatus(const std::string status);
	void addLineToPosts(const std::string new_line);
};