#include <stdio.h>

//����������������ػ�׼Ԫ�ص�����
int Partition(int arr[], int low, int high) {
	int pivot = arr[high];
	int i = low - 1;

	for (int j = low; j <= high - 1; j++) {
		//�����ǰԪ��С�ڵ��ڻ�׼Ԫ�أ���������������
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

//��������
void QuickSort(int arr[], int low, int high) {
	if (low < high) {
		int pi = Partition(arr, low, high);

		//�Ի�׼Ԫ��������������п�������
		QuickSort(arr, low, pi - 1);
		//�Ի�׼Ԫ���Ҳ����������п�������
		QuickSort(arr, pi + 1, high);
	}
}

//��ӡ����Ԫ��
void PrintArray(int arr[], int size) {
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main(void) {
	int arr[] = { -1, 2, 1, -4 };
	int n = sizeof(arr) / sizeof(arr[0]);
	printf("ԭʼ���飺");
	PrintArray(arr, n);

	QuickSort(arr, 0, n - 1);
	printf("���������飺");
	PrintArray(arr, n);

	return 0;
}