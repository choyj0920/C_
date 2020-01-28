#pragma once
class User
{
private:
	string id;
	string password;
public:
	User();
	User(string id, string password);
	void setUser(User &u);
	void setUser(string id,string pass);
	bool checkuser(string id, string pass);
	bool checkuser(string id);
	
	~User();
};

