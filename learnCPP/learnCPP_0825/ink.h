#pragma once
typedef enum color{
	red = 1, yellow, blue, white, black
}color;
typedef enum amount {
	����=1,����,����,�˳�,����
}amount;
class ink
{
	color colo;
	amount much;
	
public:
	void set(color colo, amount much);
	void setcolor(color colo);
	void setmuch(amount much);
	void print_ink();
	ink();
	~ink();
};

