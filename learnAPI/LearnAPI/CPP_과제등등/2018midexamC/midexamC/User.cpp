#include "pch.h"
#include "User.h"


User::User()
{
}

User::User(string id, string password):id(id),password(password)
{

}

void User::setUser(User & u)
{
	this->id = u.id;
	this->password = u.password;
}

void User::setUser(string id, string pass)
{
	this->id = id;
	this->password=pass;
}

bool User::checkuser(string id, string pass)
{
	return (!id.compare(this->id)) && (!pass.compare(this->password));
}

bool User::checkuser(string id)
{
	return checkuser(id, this->password);
}




User::~User()
{
}
