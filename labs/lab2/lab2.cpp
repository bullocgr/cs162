#include <fstream>
#include <iostream>
#include <stdlib.h>

using namespace std;

struct student {
	int id_num;
	string first_name;
	string last_name;
	string major;
};

student* create_student_db(int students) {
	student* arr = new student[students];
	return arr;
}

void get_student_db_info(student* arr, int students, fstream& in) {
	for (int i = 0; i < students; i++) {
		in >> arr[i].id_num;
		// cout << arr[i].id_num << endl;
		in >> arr[i].first_name;
		// cout << arr[i].first_name << endl;
		in >> arr[i].last_name;
		// cout << arr[i].last_name << endl;
		in >> arr[i].major;
		// cout << arr[i].major << endl;
	}
}

void sort_id(student* arr, int students, ofstream& output) {
	int temp;
	output << "Sorted by id number: " << endl;
	for (int i = 0; i < students; i++) {
		for (int j = 0; j < students - 1 - i; j++) {
			if (arr[j].id_num > arr[j + 1].id_num) {
				temp = arr[j].id_num;
				arr[j].id_num = arr[j + 1].id_num;
				arr[j + 1].id_num = temp;
			}
		}
		output << arr[i].id_num << endl;
	}
}

void last_name_sort(student* arr, int students, ofstream& output) {
	output << "Sorted by last name: " << endl;
	for (int i = 0; i < students; i++) {
		for (int j = 0; j < students - 1; j++) {
			if (arr[j].last_name > arr[j + 1].last_name) {
				swap(arr[j], arr[j + 1]);
			}
		}
		output << arr[i].last_name << endl;
	}
}

void majors(student* arr, int students, ofstream& output) {
	int count1 = 0;
	int count2 = 0;
	int count3 = 0;
	int count4 = 0;
	int count5 = 0;
	int count6 = 0;
	for (int i = 0; i < students; i++) {
		if (arr[i].major == "Political_Science")
			count1 ++;
		if (arr[i].major == "Criminal_Justice")
			count2 ++;
		if (arr[i].major == "Law")
			count3 ++;
		if (arr[i].major == "Communications")
			count4 ++;
		if (arr[i].major == "Public_and_Environmental_Affairs")
			count5 ++;
		if (arr[i].major == "General_Sciences")
			count6++;
	}
	if (count1 == 1, count2 == 1, count3 == 1, count4 == 1, count5 == 1, count6 == 1) {
		int final = count1 + count2 + count3 + count5 + count6;
		output << "The number of unique majors is: " << final << endl;
	}
}

void delete_student_db_info(student** arr, int students) {
	if (arr == NULL)
		return;
	delete[] (*arr);
	arr = NULL;
}

int main() {
	fstream file;
	file.open("input.txt");
	ofstream output;
	output.open("output.txt");
	int students = 0;

	if (file.is_open()) {
		file >> students;
		student* arr = create_student_db(students);
		get_student_db_info(arr, students, file);
		sort_id(arr, students, output);
		last_name_sort(arr, students, output);
		majors(arr, students, output);
		delete_student_db_info(&arr, students);
	}

	else {
		cout << "Error opening file" << endl;
	}

}