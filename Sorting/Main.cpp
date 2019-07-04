
#include <iostream>
#include <fstream>
using namespace std;


void bubbleSortSimple(unsigned int*, unsigned int, unsigned int* , unsigned int& );
void bubbleSortIverson1(unsigned int*, unsigned int, unsigned int*, unsigned int&);
void bubbleSortIverson12(unsigned int*, unsigned int, unsigned int*, unsigned int&);
void simpleInsertionsSort(unsigned int*, unsigned int, unsigned int*, unsigned int&);
void binaryInsertionsSort(unsigned int*, unsigned int, unsigned int*, unsigned int&);
void countStableSort(unsigned int*, unsigned int, unsigned int*, unsigned int&);
void radixSort(unsigned int*, unsigned int, unsigned int*, unsigned int&);
int main(){
	unsigned int arr[10]{ 3000,4000,5000,6000,1000,8000,7000,9000,10000, 2000 }; // 1 2 2 3 4 4 5 6 7 9
	unsigned int arr1[10];
	unsigned int count = 0;
	bubbleSortIverson1(arr, 10, arr1, count);
	cout << count << "\n";
	cout << arr1[0] << arr1[1] << arr1[2] << arr1[3] << arr1[4] << arr1[5] << arr1[6] << arr1[7] << arr1[8] << arr1[9] << "\n";
	count = 0;
	countStableSort(arr, 10, arr1, count);
	cout << count << "\n";
	cout << arr1[0] << arr1[1] << arr1[2] << arr1[3] << arr1[4] << arr1[5] << arr1[6] << arr1[7] << arr1[8] << arr1[9] << "\n";
	count = 0;
	radixSort(arr, 10, arr1, count);
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

//сортировка пузырьком с первым условием Айверсона
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

//сортировка пузырьком с первым и вторым условием Айверсона
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

//сортировка простыми вставками
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

//сортировка бинарными вставками
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
//поиск максимума
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

//устойчивая сортировка подсчетом
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
	operations += 3;
	for (size_t i = 0; i < array_size - 1; i++)
	{
		operations += 4;

		operations += 6;
		C[arr[i]] = C[arr[i]] + 1;
	}

	operations += 3;
	for (size_t i = 1; i < K + 1; i++)
	{
		operations += 4;

		operations += 5;
		C[i] = C[i - 1] + C[i]; // частичные суммы
	}

	//главный цикл
	operations += 3;
	for (size_t i = array_size - 1; i > 0; i--)
	{
		operations += 3;

		operations += 6;
		result[C[arr[i]]-1] = arr[i];
		operations += 6;
		C[arr[i]] = C[arr[i]] - 1;
	}

}



//юнион для цифровой сортировки
union number
{
	unsigned int num;
	unsigned char signs[4];
};
//копирует массив из юнионов
void copy_array(number* arr, unsigned int array_size, number* result, unsigned int& operations) {
	operations += 2;
	for (size_t i = 0; i < array_size; i++)
	{
		operations += 3;

		operations += 3;
		result[i] = arr[i];
	}
}

//цифровая сортировка с юнионом
void countStableSortNumeric(number* arr, unsigned int array_size,
	number* result, unsigned int& operations) {
	
	unsigned int K = 255;// max в массиве
	unsigned int* C = new unsigned int[K + 1];
	//number* C = new number[K + 1];
	//цикл по разрядам
	for (size_t glob = 0; glob < 4 ; glob++)
	{


		//обнуление
		operations += 3;
		for (size_t i = 0; i < K + 1; i++)
		{
			operations += 4;
			operations += 2;
			C[i]= 0;
		}


		//количество
		operations += 3;
		for (size_t i = 0; i < array_size ; i++)
		{
			operations += 4;

			operations += 6;
			C[arr[i].signs[glob]] = C[arr[i].signs[glob]] + 1;
		}

		operations += 3;
		for (size_t i = 1; i < K + 1; i++)
		{
			operations += 4;

			operations += 5;
			C[i] = C[i - 1] + C[i]; // частичные суммы
		}

		//главный цикл
		operations += 3;
		for (size_t i = array_size - 1; i > 0 ; i--)
		{
			operations += 3;

			operations += 6;
			result[C[arr[i].signs[glob]] - 1] = arr[i];
			operations += 6;
			C[arr[i].signs[glob]] = C[arr[i].signs[glob]] - 1;
		}
		if (glob < 4) {
			copy_array(result, array_size, arr, operations);
		}
	}
}



//цифровая сортировка 
void radixSort(unsigned int* arr, unsigned int array_size, unsigned int* result, unsigned int& operations) {
	operations = 0;
	
	number* numbers = new number[array_size];
	number* sortedNumbers = new number[array_size];

	operations += 2;
	for (size_t i = 0; i < array_size; i++)
	{
		operations += 3;
		operations += 3;
		numbers[i].num = arr[i];
	}
	//по основанию 256
	//unsigned int* count_arr = new unsigned int[256];

	
	countStableSortNumeric(numbers, array_size, sortedNumbers, operations);

	for (size_t i = 0; i < array_size; i++)
	{
		result[i] = sortedNumbers[i].num;
	}
	delete[] numbers;
	delete[] sortedNumbers;
}

