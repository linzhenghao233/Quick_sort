#include <stdio.h>

//将数组分区，并返回基准元素的索引
int Partition(int arr[], int low, int high) {
	int pivot = arr[high];
	int i = low - 1;

	for (int j = low; j <= high - 1; j++) {
		//如果当前元素小于等于基准元素，则将其放入左侧区域
		if (arr[j] < pivot) {
			i++;
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	int temp = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = temp;

	return i + 1;
}

//快速排序
void QuickSort(int arr[], int low, int high) {
	if (low < high) {
		int pi = Partition(arr, low, high);

		//对基准元素左侧的子数组进行快速排序
		QuickSort(arr, low, pi - 1);
		//对基准元素右侧的子数组进行快速排序
		QuickSort(arr, pi + 1, high);
	}
}

//打印数组元素
void PrintArray(int arr[], int size) {
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main(void) {
	int arr[] = { -1, 2, 1, -4 };
	int n = sizeof(arr) / sizeof(arr[0]);
	printf("原始数组：");
	PrintArray(arr, n);

	QuickSort(arr, 0, n - 1);
	printf("排序后的数组：");
	PrintArray(arr, n);

	return 0;
}