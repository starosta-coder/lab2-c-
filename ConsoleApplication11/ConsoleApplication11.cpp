#include <iostream>
#include <iomanip>

using namespace std;

struct fitness
{
	int release_day; //дата выпуска товара;
	int release_month;
	int release_year;
	int storage_day; //срок хранения;
	int storage_month;
	int storage_year;
	int validity_day; //срок годности;
	int validity_month;
	int validity_year;
	bool release_isCorrect();
	bool storage_isCorrect();
	bool validity_isCorrect();
};

struct product
{
	char name[32];
	float cost;
	char grade[32];
	fitness date;
	int count;
};

//3 функции корректности ввода данных для дат выпуска товаров, их хранения и сроков годности;

bool fitness::release_isCorrect()
{
	bool result = false;
	switch (release_month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
	{
		if ((release_day <= 31) && (release_day > 0))
			result = true;
		break;
	}

	case 4:
	case 6:
	case 9:
	case 11:
	{
		if ((release_day <= 30) && (release_day > 0))
			result = true;
		break;
	}

	case 2:
	{
		if (release_year % 4 != 0)
		{
			if ((release_day <= 28) && (release_day > 0))
				result = true;
		}
		else
			if (release_year % 400 == 0)
			{
				if ((release_day <= 29) && (release_day > 0))
					result = true;
			}
			else
				if ((release_year % 100 == 0) && (release_year % 400 != 0))
				{
					if ((release_day == 28) && (release_day > 0))
						result = true;
				}
				else
					if ((release_year % 4 == 0) && (release_year % 100 != 0))
						if ((release_day <= 29) && (release_day > 0))
							result = true;
		break;
	}

	default:
		result = false;
	}

	return result;
}

bool fitness::storage_isCorrect()
{
	bool result = false;
	switch (storage_month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
	{
		if ((storage_day <= 31) && (storage_day > 0))
			result = true;
		break;
	}

	case 4:
	case 6:
	case 9:
	case 11:
	{
		if ((storage_day <= 30) && (storage_day > 0))
			result = true;
		break;
	}

	case 2:
	{
		if (storage_year % 4 != 0)
		{
			if ((storage_day <= 28) && (storage_day > 0))
				result = true;
		}
		else
			if (storage_year % 400 == 0)
			{
				if ((storage_day <= 29) && (storage_day > 0))
					result = true;
			}
			else
				if ((storage_year % 100 == 0) && (storage_year % 400 != 0))
				{
					if ((storage_day == 28) && (storage_day > 0))
						result = true;
				}
				else
					if ((storage_year % 4 == 0) && (storage_year % 100 != 0))
						if ((storage_day <= 29) && (storage_day > 0))
							result = true;
		break;
	}

	default:
		result = false;
	}

	return result;
}

bool fitness::validity_isCorrect()
{
	bool result = false;
	switch (validity_month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
	{
		if ((validity_day <= 31) && (validity_day > 0))
			result = true;
		break;
	}

	case 4:
	case 6:
	case 9:
	case 11:
	{
		if ((validity_day <= 30) && (validity_day > 0))
			result = true;
		break;
	}

	case 2:
	{
		if (validity_year % 4 != 0)
		{
			if ((validity_day <= 28) && (validity_day > 0))
				result = true;
		}
		else
			if (validity_year % 400 == 0)
			{
				if ((validity_day <= 29) && (validity_day > 0))
					result = true;
			}
			else
				if ((validity_year % 100 == 0) && (validity_year % 400 != 0))
				{
					if ((validity_day == 28) && (validity_day > 0))
						result = true;
				}
				else
					if ((validity_year % 4 == 0) && (validity_year % 100 != 0))
						if ((validity_day <= 29) && (validity_day > 0))
							result = true;
		break;
	}

	default:
		result = false;
	}

	return result;
}

//функция для выделения памяти если пользователь продолжит ввод товаров;

void memory(product*& arr, int& size)
{
	product* new_array = new product[size + 1];

	for (int i = 0; i < size; i++)
	{
		new_array[i] = arr[i];
	}

	size++;

	delete[] arr;

	arr = new_array;
}

//функция сортировки по стоимости;

void sort(product* arr, int size)
{
	cout << endl;

	int k;

	cout << "Хотите отсортирвать массив? Возможна сортировка по стоимости товара (Введите 1 если да, другое число если нет): ";
	cin >> k;
	cout << endl;

	if (k == 1)
	{
		for (int i = 0; i < size; i++)
		{
			for (int i = 0; i < size - 1; i++)
			{
				if (arr[i].cost > arr[i + 1].cost)
				{
					product temp = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = temp;
				}
			}
		}

		cout << "Сортировка прошла успешно!" << endl;
	}

	else
	{
		cout << "Вы решили не сортировать" << endl;
	}

	cout << endl;
}

//функция поиска элемента по дате выпуска;

void search(product* arr, int size)
{
	cout << endl;

	int count = 0, day = 0, month = 0, year = 0;
	int s, t;

	cout << "Хотите найти нужный вам товар? Возможен поиск по дате выпуска(Нажмите 1 если да, другое число если нет): ";
	cin >> s;
	cout << endl;

	if (s == 1)
	{
		int day;
		int month;
		int year;

		cout << "Введите день выпуска: ";
		cin >> day;
		cout << endl;
		cout << "Введите номер месяца: ";
		cin >> month;
		cout << endl;
		cout << "Введите год: ";
		cin >> year;
		cout << endl;

		for (int i = 0; i < size; i++)
		{
			if (day == arr[i].date.release_day && month == arr[i].date.release_month && year == arr[i].date.release_year)
			{
				cout << "Название товара: " << arr[i].name << ", Стоимость: " << arr[i].cost << ", Сорт: " << arr[i].grade << "\n";
				cout << "Дата выпуска: " << arr[i].date.release_day << " " << arr[i].date.release_month << " " << arr[i].date.release_year << "\n";
				cout << "Срок хранения: до " << arr[i].date.storage_day << " " << arr[i].date.storage_month << " " << arr[i].date.storage_year << "\n";
				cout << "Срок годности: до " << arr[i].date.validity_day << " " << arr[i].date.validity_month << " " << arr[i].date.validity_year << endl;
				count++;
			}
		}


		if (count == 0)
		{
			cout << "Товаров с данной датой выпуска не найдено" << endl;
		}

		cout << endl;
		cout << "Продолжить поиск? Да - 1, Нет - другое число: ";
		cin >> t;
		cout << endl;

		if (t == 1)
		{
			count = 0;
			search(arr, size);
		}

		else
		{
			count = 0;
		}

	}
}

//функция вывода массива;

void conclusion(product* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Название товара: " << arr[i].name << ", Стоимость: " << arr[i].cost << ", Сорт: " << arr[i].grade << "\n";
		cout << "Дата выпуска: " << arr[i].date.release_day << " " << arr[i].date.release_month << " " << arr[i].date.release_year << "\n";
		cout << "Срок хранения: до " << arr[i].date.storage_day << " " << arr[i].date.storage_month << " " << arr[i].date.storage_year << "\n";
		cout << "Срок годности: до " << arr[i].date.validity_day << " " << arr[i].date.validity_month << " " << arr[i].date.validity_year << endl;
		cout << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "RU");

	product* arr;
	int size;

	//количество товаров не может быть меньше 1;
	do
	{
		cout << "Введите количество товаров, данные которых вы будете вводить: ";
		cin >> size;
	} while (size < 1);

	arr = new product[size];

	for (int i = 0; i < size; i++)
	{
		cout << "Введите наименование товара под номером " << i + 1 << ": ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].name, 32);
		cout << endl;

		cout << "Введите стоимость: ";
		cin >> arr[i].cost;
		cout << endl;

		cout << "Введите сорт: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].grade, 32);
		cout << endl;

		do
		{
			cout << "Введите день выпуска: ";
			cin >> arr[i].date.release_day;
			cout << endl;
			cout << "Месяц: ";
			cin >> arr[i].date.release_month;
			cout << endl;
			cout << "Год: ";
			cin >> arr[i].date.release_year;
			cout << endl;
		} while (!arr[i].date.release_isCorrect());

		do
		{
			cout << "Введите срок хранения - день: ";
			cin >> arr[i].date.storage_day;
			cout << endl;
			cout << "Месяц: ";
			cin >> arr[i].date.storage_month;
			cout << endl;

			do
			{
				cout << "Год(не может быть меньше даты выпуска): ";
				cin >> arr[i].date.storage_year;
				cout << endl;
			} while (arr[i].date.storage_year < arr[i].date.release_year);

		} while (!arr[i].date.storage_isCorrect());

		do
		{
			cout << "Введите срок годности - день: ";
			cin >> arr[i].date.validity_day;
			cout << endl;
			cout << "Месяц: ";
			cin >> arr[i].date.validity_month;
			cout << endl;

			do
			{
				cout << "Год(не может быть меньше срока хранения): ";
				cin >> arr[i].date.validity_year;
				cout << endl;
			} while (arr[i].date.validity_year < arr[i].date.storage_year);

		} while (!arr[i].date.validity_isCorrect());

		if (i == size - 1)
		{
			arr[i].count = 0;

			cout << "Хотите добавить новый товар?(Если Да - введите 1, Нет - любое другое число): ";
			cin >> arr[i].count;
			cout << endl;

			if (arr[i].count == 1)
			{
				//если пользователь продолжает ввод то вызываем функцию для выделения памяти под товар;
				memory(arr, size);
			}
		}
	}

	//если товар только 1 то сортировка и поиск невозможны;
	if (size > 1)
	{
		sort(arr, size);

		search(arr, size);
	}

	else
	{
		cout << "Функции сортировки и поиска недоступны так как пользователь ввел информацию только для 1 товара" << endl;
	}

	cout << endl;
	cout << "Вывод информации о товарах: " << endl;

	conclusion(arr, size);
}