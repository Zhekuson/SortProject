

using namespace std;

//сам swap весит 3 операции
void swap(unsigned int& t1, unsigned int& t2) {
	unsigned int temp = t1;
	t1 = t2;
	t2 = temp;
}
//сортировка обычным пузырьком
void bubbleSortSimple(unsigned int* arr, unsigned int array_size, unsigned int* result, int& operations) {
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

	operations += 1;
	result = arr;
}
void bubbleSortIverson1(unsigned int* arr, unsigned int array_size, unsigned int* result, int& operations) {
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

	operations += 1;
	result = arr;
}
void bubbleSortIverson12(unsigned int* arr, unsigned int array_size, unsigned int* result, int& operations) {
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

	operations += 1;
	result = arr;

}
void simpleInsertionsSort(unsigned int* arr, unsigned int array_size, unsigned int* result, int& operations) {
	operations = 0;

	operations += 2;
	for (size_t i = 1; i < array_size; i++)
	{
		operations += 3;

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
				arr[j + 1] = arr[i];
			}
		}
	}

	operations += 1;
	result = arr;
}
void binaryInsertionsSort(unsigned int* arr, unsigned int array_size, unsigned int* result, int& operations) {
	operations = 0;
	for (size_t i = 1; i < array_size; i++)
	{
		unsigned int left = 0, right = i - 1 , mid;
		while (right != left)
		{
			mid = (right + left) / 2;
			if (arr[mid] > arr[i]) {
				left = mid;
			}
			else
			{
				right = mid - 1;
			}

		}
		
	}

	operations += 1;
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
