void QuickSort(int* array, int left, int right)
{
	if (left < right)
	{
		int pivot = Partition(array, left, right, GettingKeys);
		QuickSort(array, left, pivot - 1);
		QuickSort(array, pivot + 1, right);
	}
}

int Partition(int* array, int low, int high, Key key)
{
	int pivot = array[high];

	int i = low - 1;
	for (int j = low; j < high; j++)
	{
		if (key(array[j]) <= key(pivot))
		{
			i++;
			Swap(array[i], array[j]);
		}
	}

	Swap(array[i + 1], array[high]);

	return i + 1;
}