//#include<stdio.h>
//#include<Windows.h>
//#include<time.h>
//
//int main() {
//	int i,j, temp,answer;
//	int nums[10];
//	srand(time(0));
//	printf("���� �迭\n");
//
//	for (i = 0; i < 10; i++) {
//		nums[i] = rand() % 1000 + 1;
//		printf("Number[%d] = %d\n", i, nums[i]);
//	}
//
//	for (i = 0; i < 10; i++) {
//		for (j = 0; j < 10 - 1; j++) {
//			if (nums[j] < nums[j + 1]) {
//				temp = nums[j];
//				nums[j] = nums[j + 1];
//				nums[j + 1] = temp;
//			}
//		}
//	}
//	printf("���ڸ� �Է��Ͻÿ�(Ȧ��: ������ ,¦��: ������ ����) : ");
//	scanf_s(" %d", &answer);
//
//	if (answer % 2) {
//		for (i = 0; i < 10; i++) {
//			
//			printf("Number[%d] = %d\n", i, nums[i]);
//		}
//	}
//	else {
//		for (i = 0; i < 10; i++) {
//
//			printf("Number[%d] = %d\n", i, nums[9-i]);
//		}
//	}
//	
//
//	system("pause");
//}