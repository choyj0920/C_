#pragma once
class DOG;
enum sal {
	많이 = 1,
	적당히,
	적게
};
class BON
{
	friend class  DOG;
private:
	int sal_q;
	
public:
	BON(int n);
	
};

