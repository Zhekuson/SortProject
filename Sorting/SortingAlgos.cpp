

using namespace std;
//todo count operations
void swap(unsigned int& t1, unsigned int& t2) {
	unsigned int temp = t1;
	t1 = t2;
	t2 = temp;
}
//сортировка обычным пузырьком
void bubbleSortSimple(unsigned int* arr, unsigned int array_size, unsigned int* result, int& operations) {
	operations = 0;
	for (size_t i = 0; i < array_size - 1; i++)
	{
		for (size_t j = 0; j < array_size - i; j++)
		{
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
	result = arr;
}
void bubbleSortIverson1(unsigned int* arr, unsigned int array_size, unsigned int* result, int& operations) {
	operations = 0;
	bool swapped;
	for (size_t i = 0; i < array_size - 1; i++)
	{
		swapped = false;
		for (size_t j = 0; j < array_size - i; j++)
		{
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				swapped = true;
			}
		}
		if (!swapped) {
			break;
		}
	}
	result = arr;
}
void bubbleSortIverson12(unsigned int* arr, unsigned int array_size, unsigned int* result, int& operations) {
	operations = 0;
	bool swapped;
	unsigned int lastSwapped = array_size - 1;
	unsigned int Bound = array_size - 1;
	for (size_t i = 0; i < array_size - 1; i++)
	{
		Bound = lastSwapped;
		lastSwapped = 0;
		swapped = false;
		for (size_t j = 0; j < Bound; j++)
		{
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				swapped = true;
				lastSwapped = j;
			}
		}
		if (!swapped) {
			break;
		}
	}
	result = arr;

}
void simpleInsertionsSort(unsigned int* arr, unsigned int array_size, unsigned int* result, int& operations) {
	operations = 0;
	for (size_t i = 1; i < array_size; i++)
	{
		for (size_t j = i - 1; j >= 0; j--)
		{
			if (arr[i] < arr[j]) {
				arr[j + 1] = arr[j];
			}
			else
			{
				arr[j + 1] = arr[i];
			}
		}
	}
	result = arr;
}
void binaryInsertionsSort(unsigned int* arr, unsigned int array_size, unsigned int* result, int& operations) {
	operations = 0;
	for (size_t i = 1; i < array_size; i++)
	{
		for (size_t j = i - 1; j >= 0; j--)
		{
			if (arr[i] < arr[j]) {
				arr[j + 1] = arr[j];
			}
			else//todo binary
			{
				arr[j + 1] = arr[i];
			}
		}
	}
	result = arr;
}
unsigned int find_Max(unsigned int* arr, unsigned int& array_size) {
	unsigned int maximum = arr[0];
	for (size_t i = 1; i < array_size; i++)
	{
		if (arr[i] > maximum) {
			maximum = arr[i];
		}
	}
}

void countStableSort(unsigned int* arr, unsigned int array_size, unsigned int* result, int& operations) {
	operations = 0;
	unsigned int K = find_Max(arr, array_size);// max в массиве
	unsigned int* C = new unsigned int[K+1];
	for (size_t i = 0; i < K+1; i++)
	{
		C[i] = 0;
	}
	for (size_t i = 0; i < array_size - 1; i++)
	{
		C[arr[i]] = C[arr[i]] + 1;
	}
	for (size_t i = 1; i < K+1; i++)
	{
		C[i] = C[i - 1] + C[i]; // частичные суммы
	}
	//главный цикл
	for (size_t i = array_size; i >= 0; i--)
	{
		result[C[arr[i]] - 1] = arr[i];
		C[arr[i]] = C[arr[i]] - 1;
	}
	
}
void numericSort(unsigned int* arr, unsigned int array_size, unsigned int* result, int& operations) {

}
