#pragma once
#include <string>

///////////////////////////////////////////////////////////
/*														 //
	Those definitions are used for tests,                //
	you can add your own, but please do not delete any.  //
*/														 //
enum DeviceType { PHONE, PC, LAPTOP, TABLET };		     //
//
#define UbuntuOS "UbuntuLinux"                           //						
#define RedHatOS "RedHatLinux"							 //
#define MacOS "MacOS"									 //
#define IOS "IOS"										 //
#define WINDOWS7 "Windows7"                              //
#define WINDOWS10 "Windows10"                            //
#define WINDOWS11 "Windows11"                            //
#define ANDROID "Android"                                //
														 //
/// ///////////////////////////////////////////////////////


class Device
{
private:
	std::string os;
	bool active;
	unsigned int id;
	DeviceType type;

public:
	// methods that don't change the artibutes of the object
	std::string getOS() const;
	bool isActive() const;
	unsigned int getID() const;
	DeviceType getType() const;
	bool isWindows() const;

	// methods that change the artibutes of the object
	void activate();
	void deactivate();
	void init(const unsigned int id, const DeviceType type, const std::string os);
};