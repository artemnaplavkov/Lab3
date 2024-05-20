#pragma once
#include <string>

class notebook {
	std::string name;
	int year;
	int ram;
	int ssd;
	float price;

public:
	void input();
	const std::string& get_name();
	friend std::istream& operator>>(std::istream&, notebook&);
	friend std::ostream& operator<<(std::ostream&, const notebook&);
};



void create(notebook** arr, int* n);
void write(notebook* arr, int n);
void read(notebook** arr, int* n);
void print(notebook* arr, int n);
void find(notebook* arr, int n);
