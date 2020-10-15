/*Найти в строке последовательность одинаковых символов максимальной длины и переписать в выходную строку в виде 
n1,n2c – начало и длина фрагмента и символ, например abcddddddddddddedfg -> 3,12d. Из исходной строки фрагмент удалить.
Повторять этот процесс. Пока в строке есть последовательности, в конце переписать остаток в выходную строку.*/
#include <iostream>
#include <string>
using namespace std;
void abc() {
	int n_begin, max_k = 0, k = 1, i, max_n = 0;
	char b[20], a = 'a', max_a = 'a'; 
	cout << "Enter the string" << endl;
	fgets(b, 20, stdin);
	a = b[0];
	n_begin = 0;
	for (i = 1; b[i] == '\0'; i++) {
		if (a == b[i]) {
			a = b[i];
			k++;
		}
		else
			if (max_k < k) {
				max_k = k;
				max_n = n_begin;
				max_a = a;
				a = b[i];
				n_begin = i;
				k = 1;
			}
	}
	for (i = n_begin; i <= max_n; i++) {
		b[i] = b[i + max_k];
		if (b[i] == '\0')
			break;
		}
	for (i = 1; b[i] == '\0'; i++) {
		cout << b[i];
	}
}
int main()
{ 
	void a();
	return 0;
}
    