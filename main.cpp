#include <iostream>
#include "store.h"



int main() {
	int stop = 0;
	notebook* arr = NULL;
	int n = 0;
	while (stop != 1) {
		printf("1-read 2-create 3-print 4-find\n");
		int key;
		std::cin >> key;
		switch (key) {
		case 1:
			read(&arr, &n);
			break;
		case 2:
			create(&arr, &n);
			write(arr, n);
			break;
		case 3:
			print(arr, n);
			break;
		case 4:
			find(arr, n);
			break;
		default:
			std::cout << "bye\n";
			stop = 1;
			break;
		}
	}
}