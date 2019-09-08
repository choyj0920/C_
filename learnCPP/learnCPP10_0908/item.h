#pragma once
class item
{
	string name;
	int price;
	int grade;
public:
	item(string name, int price, int grade) :name(name), price(price), grade(grade)
	{
	}
	item() {

	}
	void show_info();
	void show_info2();
	static void save_file(map<string, item>* inven, int item_count) {
		
		ofstream out("Data.txt");
		map<string, item> ::iterator iter;
		for (iter = inven->begin(); iter != inven->end(); ++iter) {
			out << (*iter).first << '\t' << (*iter).second.price << '\t' << (*iter).second.grade << endl;
		}
		cout << "파일 저장 완료!" << endl;
		out.close();
	}
	~item();
};

