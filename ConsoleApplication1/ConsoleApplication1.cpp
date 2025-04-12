#include <stdio.h>


/*
Подсчитать число единиц во всех разрядах заданного двоичного числа Х
(вес).
*/

int main() {

	
	int sh=0, c1=0,count=0,count2=0;
	printf("vvod 16-i: ");
	scanf_s("%x", &sh);		//16-ое число
	printf("vvod celoe: ");
	scanf_s("%d", &c1);		//10-ое число
	printf("\nresult sh=%d  c=%d", sh, c1);
	
	_asm {
		mov eax, sh
		mov count, 0; счетчик для подсчета единиц
		a1 : test eax, eax; не ноль ?
		je exit
		shr eax, 1; очередной сдвиг
		adc count, 0; если был перенос - увеличим счетчик.count = count + CF
		jmp a1
		exit :

		mov eax, c1
			mov count2, 0; счетчик для подсчета единиц
			a2 : test eax, eax; не ноль ?
			je exit2
			shr eax, 1; очередной сдвиг
			adc count2, 0; если был перенос - увеличим счетчик. count2 = count2 + CF
			jmp a2
			exit2 :
		
	}

	
		printf("\n kol-vo (1): %d = %d, %d = %d", sh, count, c1, count2);

	return 0;
}