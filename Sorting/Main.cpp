
#include <iostream>
#include <fstream>
using namespace std;


void bubbleSortSimple(unsigned int*, unsigned int, unsigned int* , unsigned int& );
void bubbleSortIverson1(unsigned int*, unsigned int, unsigned int*, unsigned int&);
void bubbleSortIverson12(unsigned int*, unsigned int, unsigned int*, unsigned int&);
void simpleInsertionsSort(unsigned int*, unsigned int, unsigned int*, unsigned int&);
void binaryInsertionsSort(unsigned int*, unsigned int, unsigned int*, unsigned int&);
void numericSort(unsigned int*, unsigned int, unsigned int*, unsigned int&);
void countStableSort(unsigned int*, unsigned int, unsigned int*, unsigned int&);

int main(){
	unsigned int arr[10]{ 9,2,4,7,4,2,1,3,5, 6 }; // 1 2 2 3 4 4 5 6 7 9
	unsigned int arr1[10];
	unsigned int count = 0;
	bubbleSortIverson1(arr, 10, arr1, count);
	cout << count << "\n";
	cout << arr1[0] << arr1[1] << arr1[2] << arr1[3] << arr1[4] << arr1[5] << arr1[6] << arr1[7] << arr1[8] << arr1[9] << "\n";
	count = 0;
	countStableSort(arr, 10, arr1, count);
	cout << count << "\n";
	cout << arr1[0] << arr1[1] << arr1[2] << arr1[3] << arr1[4] << arr1[5] << arr1[6] << arr1[7] << arr1[8] << arr1[9] << "\n";

	cin >> count;
}

//Меняет местами. swap весит 3 операции
void swap(unsigned int& t1, unsigned int& t2) {
	unsigned int temp = t1;
	t1 = t2;
	t2 = temp;
}
//Копирует массив. Не должен учитываться, потому что не входит в сортировку
void copy_array(unsigned int* arr, unsigned int array_size, unsigned int* result) {
	for (size_t i = 0; i < array_size; i++)
	{
		result[i] = arr[i];
	}
}
//сортировка обычным пузырьком
void bubbleSortSimple(unsigned int* arr, unsigned int array_size, 
	unsigned int* result, unsigned int&  operations) {
	operations = 0;

	operations += 3;//i=0 присвоение и i < array_size - 1 
	for (size_t i = 0; i < array_size - 1; i++)
	{

		operations += 4;//i < arrsize-1, i++
		operations += 3;// j = 0 j < arrsize-i
		for (size_t j = 0; j < array_size - i; j++)
		{
			operations += 4;// j++ и сравнение с arrsize
			operations += 4; // j+1, aj, aj+1, > 
			if (arr[j] > arr[j + 1]) {
				operations += 6;
				swap(arr[j], arr[j + 1]);
			}
		}
	}

	copy_array(arr, array_size, result);
}

//сортировка
void bubbleSortIverson1(unsigned int* arr, unsigned int array_size,
	unsigned int* result, unsigned int&  operations) {
	operations = 0;
	bool swapped;
	operations += 3;//i=0 присвоение и i < array_size - 1 
	for (size_t i = 0; i < array_size - 1; i++)
	{
		operations += 4;//i < arrsize-1, i++
		operations += 1;//присвоение swapped 
		swapped = false;
		operations += 3;// j = 0 j < arrsize-i
		for (size_t j = 0; j < array_size - i; j++)
		{
			operations += 4;// j++ и сравнение с arrsize
			operations += 4; // j+1, a[j], a[j+1], > 
			if (arr[j] > arr[j + 1]) {
				operations += 6;
				swap(arr[j], arr[j + 1]);
				operations += 1;
				swapped = true;
			}
		}
		operations += 1;
		if (!swapped) {
			break;
		}
	}

	copy_array(arr, array_size, result);
}
void bubbleSortIverson12(unsigned int* arr, unsigned int array_size,
	unsigned int* result, unsigned int&  operations) {
	operations = 0;
	bool swapped;

	operations += 2;
	unsigned int lastSwapped = array_size - 1;
	unsigned int Bound = array_size - 1;

	operations += 3;
	for (size_t i = 0; i < array_size - 1; i++)
	{
		operations += 4;//цикл

		operations += 3;
		Bound = lastSwapped;
		lastSwapped = 0;
		swapped = false;

		operations += 2;
		for (size_t j = 0; j < Bound; j++)
		{
			operations += 3;//цикл
			operations += 4;//взятие и сравнение
			if (arr[j] > arr[j + 1]) {

				operations += 6;
				swap(arr[j], arr[j + 1]);

				operations += 2;
				swapped = true;
				lastSwapped = j;
			}
		}
		operations += 1;
		//нет смысла проверять lastswapped, потому что они меняются в одном месте
		if (!swapped) {
			break;
		}
	}
	copy_array(arr, array_size, result);
}
void simpleInsertionsSort(unsigned int* arr, unsigned int array_size,
	unsigned int* result, unsigned int&  operations) {
	operations = 0;

	operations += 2;
	for (size_t i = 1; i < array_size; i++)
	{
		operations += 3;

		//operations += 1;
		unsigned int num = arr[i];

		operations += 3;
		for (size_t j = i - 1; j >= 0; j--)
		{
			operations += 3;

			operations += 3;
			if (arr[i] < arr[j]) {
				operations += 3;
				arr[j + 1] = arr[j];
			}
			else
			{
				operations += 3;
			 	arr[j+1] = num;
				break;
			}
		}
	}

	copy_array(arr, array_size, result);
}
void binaryInsertionsSort(unsigned int* arr, unsigned int array_size,
	unsigned int* result, unsigned int&  operations) {
	operations = 0;

	operations += 2;
	for (size_t i = 1; i < array_size; i++)
	{
		operations += 3;//цикл

		operations += 4;
		unsigned int left = 0, right = i - 1, mid = i;

		operations += 1;
		while (left != mid)
		{
			operations += 3;
			mid = (right + left) / 2;

			operations += 3;
			if (arr[mid] > arr[i]) {
				operations += 2;
				right = mid - 1;
			}
			else
			{
				operations += 1;
				left = mid;
			}

		}
		unsigned int position;

		operations += 3;
		if (arr[i] > arr[left]) {
			operations += 3;
			if (arr[i] > arr[right]) {
				operations += 2;
				left = right + 1;
			}
			else
			{
				operations += 1;
				left = right;
			}
		}

		//сдвиг
		operations += 2;
		for (size_t k = i; k > left; k--)
		{
			operations += 3;//цикл

			operations += 4;
			arr[k] = arr[k - 1];
		}

		operations += 3;
		arr[left] = arr[i];
	}

	copy_array(arr, array_size, result);
}
//поиск максимума. 
unsigned int find_Max(unsigned int* arr, unsigned int& array_size,
	unsigned int& operations) {
	operations += 1;
	unsigned int maximum = arr[0];

	operations += 2;
	for (size_t i = 1; i < array_size; i++)
	{
		operations += 3;
		operations += 2;
		if (arr[i] > maximum) {
			operations += 2;
			maximum = arr[i];
		}
	}
	return maximum;
}

void countStableSort(unsigned int* arr, unsigned int array_size, 
	unsigned int* result, unsigned int& operations) {
	operations = 0;
	unsigned int K = find_Max(arr, array_size, operations);// max в массиве
	unsigned int* C = new unsigned int[K + 1];
	//обнуление
	operations += 3;
	for (size_t i = 0; i < K + 1; i++)
	{
		operations += 4;
		operations += 2;
		C[i] = 0;
	}


	//количество
	operations +=
	for (size_t i = 0; i < array_size - 1; i++)
	{
		C[arr[i]] = C[arr[i]] + 1;
	}
	for (size_t i = 1; i < K + 1; i++)
	{
		C[i] = C[i - 1] + C[i]; // частичные суммы
	}
	//главный цикл
	for (size_t i = array_size - 1; i > 0; i--)
	{
		result[C[arr[i]]-1] = arr[i];
		C[arr[i]] = C[arr[i]] - 1;
	}

}
void numericSort(unsigned int* arr, unsigned int array_size, unsigned int* result, int& operations) {

}

