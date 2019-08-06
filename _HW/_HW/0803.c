//#include<stdio.h>
//#include<Windows.h>
//
//void find_(const char* word, const char* word_find);
//
//int main() {
//
//	char user_str[100] = { 0,};
//	char find_str[100] = { 0, };
//
//	printf("문자열을 입력하세요 : ");
//	gets(user_str);
//	printf("찾으려는 문자열을 입력하세요 : ");
//	gets(find_str);
//
//	find_(user_str, find_str);
//
//	
//	
//	system("pause");
//}
//
//void find_(const char* word ,const char* word_find) {
//	int word_len = strlen(word);
//	int word_find_len = strlen(word_find);
//	int j, match = 0;
//	char* p1= word;
//	char* fp = word + word_len - word_find_len;
//	
//	while (p1 <= fp) {
//		
//		if (*p1 == *word_find) {
//			for (j = 0; j < word_find_len; j++) {
//				if (*(p1 + j) != *(word_find + j)) { match = 0; break; }
//				match = 1;
//			}
//			if (match) {
//				printf("찾으시는 문자열 %s 은 %s 문자열의 %d 번째에 있습니다.", word_find, word, (p1 - word) / sizeof(char) + 1);
//				return;
//			}
//		}
//		p1++;
//	}
//
//}
