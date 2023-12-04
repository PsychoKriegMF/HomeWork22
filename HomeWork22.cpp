#include <iostream>

void print_arr(int arr[], const int length) {
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ' ';
	std::cout << std::endl;
}
void swap(int* num1, int* num2) {
	int tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}
void swap_in_arr(int arr[], const int length) {
	for (int i = 0; i < length; i++)
		if (i % 2 == 0)
			swap(arr + i, arr + i + 1);
	std::cout << std::endl;
}

// Мне кажется это правильный вариант именно сортировки "чётных и нечётных ЭЛЕМЕНТОВ массива по чётным и нечётным позициям массива". 
// P/s. сам себе жизнь усложнил походу
void swap_in_arr2(int arr[], const int length) {
	for (int i = 0; i < length; i += 2)
		if (*(arr + i) % 2 == 0 && *(arr + i + 1) % 2 == 0)
			continue;
		else
			if (*(arr + i) % 2 == 0 )
				swap(arr + i, arr + i + 1);
			else
				if(*(arr + i + 1) % 2 == 0)
					swap(arr + i, arr + i + 1);
	std::cout << std::endl;
}
// Третий вариант решения
void swap_in_arr3(int arr[], const int length) {             
	int* ptr = &arr[0];
	for (int i = 0;i < length- 1; i+=2)
		swap(ptr + i, ptr + i + 1);
	std::cout << std::endl;
}
void power(int* num1, int num2) {
	int tmp = *num1;
	if (num2 == 0)
		*num1 = 1;	
	for (int i = 1; i < num2; i++)
		*num1 *= tmp;	
}


int main() {
	setlocale(LC_ALL, "ru");


	
	std::cout << "Задача 1. Чётные и нечётные элементы массива.\n\n";
	const int size = 10;
	int arr[size]{ 1,2,3,4,5,6,7,8,9,10 };
	print_arr(arr, size);	
	std::cout << "Меняем местами всё чётные и нечётные \"элементы\" массива и получаем:\n";
	swap_in_arr(arr, size);
	print_arr(arr, size);
	
	

	/*Ну тут честно я затроил по поводу элементов массива... По задаче выглядит, что нужно поменять местами чётные и нечётные "позиции"
	(как я вижу и понимаю, поменять местами элементы, которые находятся на чётных и нечётных позициях), а написано поменять чётные и нечётные элементы...
	// Поэтому вариант второй: если оба элемента на чётной и нечётной позиции являются чётными или нечётными мы их не меняем.*/
	std::cout << "\nТ.к. я затупил с определениями, для сортировки четных \"элементов\" массива,\nсвапнем элементы в моем понимании.\n";
	const int size2 = 10;
	int arr2[size2]{ 10,12,13,14,25,66,17,83,92,101 };
	print_arr(arr2, size2);
	std::cout << "Меняем местами всё чётные и нечётные элементы массива и получаем:";
	swap_in_arr2(arr2, size2);
	print_arr(arr2, size2);
	
	std::cout << "\nТретий вариант решения.\n";
	
	print_arr(arr, size);
	swap_in_arr3(arr, size);
	print_arr(arr, size);
	
	
	std::cout << "\nЗадача 2.\n";
	int m;
	int n;	
	std::cout << "Введите число -> ";
	std::cin >> n;
	std::cout << "Введите степень -> ";
	std::cin >> m;	
	power(&n, m);
	std::cout << n;
	
	
	


	return 0;
}