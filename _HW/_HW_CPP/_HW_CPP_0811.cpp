
#include "pch.h"
#include <iostream>
#include "character.h"

int main()
{
	int chara_count = 0;
	int temp_pers;
	int temp_trib;
	char temp_name[10] = { 0, };
	character* chara_list;
	cout << "<캐릭터를 만들겠습니다>" << "\n몇 명을 만들까요? : ";
	cin >> chara_count;
	chara_list = new character[chara_count];
	for (int i = 0; i < chara_count;i++) {
		cout << i + 1 << "번째 캐릭터 생성\n" << "이름을 입력하세요 : ";
		cin >> temp_name;
		cout << "1.인간\n" << "2.악마\n" << "종족을 선택하세요 : ";
		cin >> temp_trib;
		cout << "1.난폭한.\n2.예민한.\n3.평범한.\n4.무난함.\n5.게으른.\n" << "셩격을 선택하세요 : ";
		cin >> temp_pers;
		(chara_list + i)->SetInfo(temp_name, temp_pers, temp_trib);
	}
	cout << "<결과를 확입합니다>\n";
	for (int i = 0; i < chara_count;i++) {
		
		(chara_list + i)->ShowInfo();
	
	}

	delete[] chara_list;
	system("pause");
	return 0;
}

