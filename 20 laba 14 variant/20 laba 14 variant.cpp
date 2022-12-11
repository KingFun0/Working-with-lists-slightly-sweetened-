//Индивидуальное задание :
//Реализовать следующие функции для работы с однонаправленным
//списком :
//-удаление всех элементов с указанным значением;	+
//-добавление элемента после второго четного;	+
//-добавление элемента в начало списка;		+
//-добавление элемента перед первым отрицательным;	+
//-вывод последнего четного элемента списка на экран.
//Работу программы реализовать с помощью меню.

#include <iostream>
using namespace std;
struct list
{
	int inf;
	struct list* next;
};
void add_last(list** head, int add_inf) {

	list* add = new list;
	add->inf = add_inf;
	add->next = NULL;

	if (*head != NULL) {
		list* ptr;
		ptr = *head;
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next = add;
	}
	else *head = add;
}
void print_list(list** head) {
	list* ptr;
	ptr = *head;
	cout << "Список " << endl;
	if (ptr == NULL) cout << " пуст";
	else {
		while (ptr != NULL) {
			cout << ptr->inf << "  ";
			ptr = ptr->next;
		}
		cout << endl;
	}
	cout << endl;
}
void add_first(list** head, int add_inf) {
	list* add = new list;
	add->inf = add_inf;

	if (*head != NULL) {
		add->next = *head;
		*head = add;
	}
	else {
		add->next = NULL;
		*head = add;

	}
	cout << endl;
}
void removing_all_elements_with_the_specified_value(list** head, int number) {
	if (*head != NULL) {
		list* ptr;
		ptr = *head;
		while (ptr->inf == 0) {
			list* lala;
			lala = ptr;
			ptr = ptr->next;
			delete lala;
			*head = ptr;
			if (ptr == NULL) { return; }
		}
		while (ptr->next != NULL) {
			if ((ptr->next)->inf == number) {
				list* lala;
				lala = ptr->next;
				ptr->next = lala->next;
				delete lala;

			}
			else
			{
				ptr = ptr->next;
				if (ptr == NULL) { return; }
			}

		}


	}
	else {
		cout << "Список пуст" << endl;
	}
}
void adding_an_element_after_the_second_even(list** head, int number) {
	list* ptr;
	int counter = 0;
	int score = 0;
	if (*head != NULL) {
		ptr = *head;
		while (ptr != NULL) {
			if (ptr->inf % 2 == 0) {
				counter++;
			}
			if (counter == 2) {
				list* lala = new list;
				lala->inf = number;
				lala->next = ptr->next;
				ptr->next = lala;
				ptr = ptr->next;
				score++;
			}
			ptr = ptr->next;
			if (score == 1) {
				break;
			}
		}
	}
	else {
		cout << "список пуст";
	}
	cout << endl;
}
void adding_an_element_before_the_first_negative(list** head, int number) {
	list* ptr;
	int fol = 0;
	list* second_ptr;
	if (*head != NULL) {
		ptr = *head;
		while (ptr != NULL) {
			if (ptr->inf < 0) {
				fol++;
			}
			if (fol == 1) {
				list* lala = new list;
				lala->inf = number;
				if (*head != NULL) {
					lala->next = *head;
					*head = lala;
				}
				else {
					lala->next = NULL;
					*head = lala;

				}
			}
			second_ptr = ptr;
			ptr = ptr->next;
			while (ptr != NULL) {

				if (ptr->inf == number) {

					list* lala = new list;
					lala->inf = number;
					lala->next = ptr;
					second_ptr->next = lala;

					second_ptr = second_ptr->next;
				}
				second_ptr = second_ptr->next;
				ptr = ptr->next;
			}
		}
	}

}
void print_the_last_even_element_of_the_list_to_the_screen(list** head) {
	list* ptr;
	int last_elem = 0;
	int joi = 0;
	int pok = 0;
	if (*head != NULL) {
		ptr = *head;
		while (ptr != NULL) {
			if (ptr->inf % 2 == 0) {
				joi++;
				last_elem = ptr->inf;
			}
			ptr = ptr->next;
		}

		if (joi == joi) {
			cout << last_elem << " ";
		}
		else {
			cout << "список пуст";
		}
	}
	cout << endl;
}
int main()
{
	setlocale(LC_ALL, "RUS");
	list** head = new list*;
	*head = NULL;
	while (true) {
		cout << "1. Добавление в начало " << endl;
		cout << "2. Добавление в конец " << endl;
		cout << "3.удаление всех элементов с указанным значением " << endl;
		cout << "4.добавление элемента после второго четного " << endl;
		cout << "5.добавление элемента перед первым отрицательным " << endl;
		cout << "6.вывод последнего четного элемента списка на экран " << endl;
		int p;
		cin >> p;
		switch (p) {
		case 1: {
			int a;
			cout << "Введите добавляемое значение " << endl;
			cin >> a;
			add_first(head, a);
			print_list(head);
			break;
		}
		case 2: {
			int a;
			cout << "Введите добавляемое значение " << endl;
			cin >> a;
			add_last(head, a);
			print_list(head);
			break;
		}
		case 3: {
			int number;
			cout << "Введите значение которое необходимо удалить: " << endl;
			cin >> number;
			removing_all_elements_with_the_specified_value(head, number);
			print_list(head);
			break;
		}
		case 4: {
			int one;
			cout << "Введите любое значение: " << endl;
			cin >> one;
			adding_an_element_after_the_second_even(head, one);
			print_list(head);
			break;
		}
		case 5: {
			int two;
			cout << "Введите число которое хотим добавить: " << endl;
			cin >> two;
			adding_an_element_before_the_first_negative(head, two);
			print_list(head);
			break;
		}
		case 6: {
			print_the_last_even_element_of_the_list_to_the_screen(head);
			print_list(head);
			break;
		}
		}
	}

}