#include "store.h"
#include <fstream>
#include <iostream>
#include <string>


void notebook::input() {
	std::cout << "name = ";
	std::cin >> name;
	std::cout << "year = ";
	std::cin >> year;
	std::cout << "ram = ";
	std::cin >> ram;
	std::cout << "ssd = ";
	std::cin >> ssd;
	std::cout << "price = ";
	std::cin >> price;
}

const std::string& notebook::get_name() {
	return name;
}

std::istream& operator>>(std::istream& is, notebook&note) {
	is >> note.name >> note.year >> note.ram >> note.ssd >> note.price;
	return is;
}

std::ostream& operator<<(std::ostream& os, const notebook& note) {
	os << note.name << "\t" << note.year << "\t" << note.ram << "\t" << note.ssd << "\t" << note.price;
	return os;
}

void create(notebook **arr, int *n) {
	if (*n > 0) {
		delete[](*arr);
		*n = 0;
	}
	std::cout << "notebooks number = ";
	std::cin >> *n;
	if (*n < 1)
		return;
	*arr = new notebook[*n];
	for (int i = 0; i < *n; i++) {
		std::cout << "notebook " << (i + 1) << "\n";
		(*arr)[i].input();
	}
}

void write(notebook* arr, int n) {
	if (n == 0)
		return;
	std::ofstream os("notebooks.txt");
	os << n << "\n";
	for (int i = 0; i < n; i++)
		os << arr[i] << "\n";
}

void read(notebook** arr, int* n) {
	if (*n > 0) {
		delete[] (*arr);
		*n = 0;
	}
	std::ifstream is("notebooks.txt");
	std::cin >> *n;
	if (*n < 1)
		return;
	*arr = new notebook[*n];
	for (int i = 0; i < *n; i++)
		is >> (*arr)[i];
}

void print(notebook* arr, int n) {
	if (n == 0)
		return;
	std::cout << "name\tyear\tram\tssd\tprice\n";
	for (int i = 0; i < n; i++)
		std::cout << arr[i] << "\n";
}

void find(notebook* arr, int n) {
	if (n == 0)
		return;
	std::cout << "name = ";
	std::string name;
	std::cin >> name;
	std::cout << "name\tyear\tram\tssd\tprice\n";
	for (int i = 0; i < n; i++)
		if (name == arr[i].get_name())
			std::cout << arr[i] << "\n";
}
