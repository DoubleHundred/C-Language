#include <stdio.h>

int frwd (int a, int b) {	//a: ASCII / b: cnge
	if (a == 0) {
		return 0;
	}
	
	if ((a - b) < 97) {
		b += (a - 97);
		a = (122 - b);
		
		return (a);
	}
	
	else {
		a -= b;
		
		return (a);
	}
}

int bcwd (int a, int b) {	//a: ASCII / b: cnge
	if (a == 0) {
		return 0;
	}
	
	if ((a + b) > 122) {
		b -= (123 - a);
		a = 97 + b;
		
		return (a);
	}
	
	else {
		a += b;
		
		return (a);
	}
}

int main() {
	int cnge = 0, pm = 0, N = 0;	//cnge: 얼마나 앞당길지 / pm: 앞으로, 뒤로
	
	char str[100] = { 0 };
	int ASCII[100] = { 0 };
	
	printf("암호를 얼마나 앞(1)/뒤(2) 당길지 선택 ex) 2 1 -> 2칸 앞으로: \n");
	scanf("%d %d", &cnge, &pm);
	
	printf("\n문자열을 입력하세요 (조건: Small Eng, 100, space X) \n");
	scanf("%s", str);
		
	for (int q = 0; q < 100; q++) {
		ASCII[q] = str[q];
		
		if (pm == 1) {
			ASCII[q] = frwd(ASCII[q], cnge);
		}
		else if (pm == 2) {
			ASCII[q] = bcwd(ASCII[q], cnge);
		}
		else {
			printf("\nerror");
			return 0;
		}

	}
	
	for (int q = 0; ASCII[q] >= 97 && 122 >= ASCII[q]; q++) {
		N++;
	}

	for (int q = 0; q < N; q++) {
		printf("%c", ASCII[q]);
	}
	
	
	return 0; 
}
