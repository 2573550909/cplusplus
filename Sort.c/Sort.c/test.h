#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void InsertSort(int* array, int size)
{
	for (int i = 0; i < size; ++i)
	{//0, 5, 1, 7, 6, 3, 4, 2, 9, 8 
		int key = array[i];
		int end = i - 1;
		while (end >= 0 && array[end] > key)
		{
			array[end + 1] = array[end];
			end--;
		}
		array[end + 1] = key;
	}
}


//���뷨������Ż�---���ֲ��ҷ�
void InsertSort2(int* array, int size)
{
	for (int i = 0; i < size; ++i)
	{
		int key = array[i];
		int end = i - 1;
		int left = 0;
		int mid = 0;
		while (left <= end)
		{
			mid = (left+end) / 2;
			if (key < array[mid])
			{
				end = mid - 1;
			}
			if(key>=array[mid])
			{
				left = mid+1;
			}
		}//0 1 2 2 3 4 4 5 6 7 8 9 12 15 32 45 58 65 85   =>  46
		for (int j = i - 1; j >= end; j--)
		{
			array[j + 1] = array[j];
		}
		array[left] = key;
	}
}

void InsertSort3(int* array, int size)
{
	for (int i = 0; i < size; i++) {
		//��¼��ǰҪ�Ƚϵ���
		int min = array[i];
		//��ߵĽ��޳�ʼ��Զ�� 0
		int left = 0;
		//�ұ����ǵ�ǰ��������һλ
		int right = i - 1;
		int mid = 0;
		//whileѭ����������Ϊ��ȷ��left �� right����ȷֵ�������Ҫ�������ȷ���䣬ֱ��left��right������������ȷ����Ķ��壬��ô��˵�������ҵ���
		while (left <= right) {
			mid = (left + right) / 2;
			//�����ǰҪ�Ƚϵ�ֵС���м�ֵ��ô��right�����м�ֵ�����һλ
			if (min < array[mid])
				right = mid - 1;
			else//��������м�ֵ����ôleft�����м�ֵ���Ҳ�һλ
				left = mid + 1;
		}
		//whileѭ�������󣬴�left(�������ֵ)����ǰi�ķ�Χ�����δ�������Ҳำֵ
		for (int j = i - 1; j >= left; j--) {
			array[j + 1] = array[j];
		}
		//���Ҫ�ǵý�leftλ�õ�ֵ�滻Ϊmin
		array[left] = min;
	}
}



void ShellSort(int* array, int size)
{
	int gap = 3;
	while (gap)
	{
		for (int i = gap; i < size; ++i)
		{
			int key = array[i];
			int end = i - gap;
			while (end >= 0 && array[end] > key)
			{
				array[end + gap] = array[end];
				end -= gap;
			}
			array[end + gap] = key;
		}
		gap--;
	}
}

void Swap(int *left, int *right)
{
	int tmp = *left;
	*left = *right;
	*right = tmp;
}

typedef int(*Cmp)(int, int);

int Less(int x, int y)
{
	return x > y ? 1 : 0;
}

int Great(int x, int y)
{
	return x > y ? 0 : 1;
}

void SelectSort(int *array, int size,Cmp cmp)
{
	for (int i = 0; i < size-1; ++i)
	{
		//0, 5, 1, 7, 6, 2, 4, 3, 9, 8
		int maxPos = 0;
		for (int j = 1; j < size-i; ++j)
		{
			 if(cmp(array[j], array[maxPos])==0)
			 {
				maxPos = j;
			 }
		}
		//����if����д��д
		//��˼�ǣ��������Ԫ���±�������������ȷλ�þͲ�����
		if (maxPos != size - i - 1)
		{
			Swap(&array[maxPos], &array[size - i - 1]);
		}
	}
}

//ѡ������
void SelectSort2(int *array, int size)
{
	int begin = 0;
	int end = size - 1;
	int j = 0;

	while (begin<end)
	{
		//3, 5, 1, 9, 6, 2, 4, 7, 8, 0 
		int maxPos = begin;
		int minPos = begin;
		for(j = begin;j<=end;j++)
		{
			if (array[j]>array[maxPos])
			{
				maxPos = j;
			}

			if (array[j]< array[minPos])
			{
				minPos = j;
			}
		}

		if (maxPos != end)
		{
			Swap(&array[maxPos], &array[end]);
		}

		if (minPos == end)
		{
			minPos = maxPos;
		}

		if (minPos != begin)
		{
			Swap(&array[minPos], &array[begin]);
		}
		end--;
		begin++;
	}
}

void AdjustDown(int *array, int size, int last)
{
	int child = last * 2 + 1;
	while (child < size)
	{
		if(child + 1 < size && array[child] < array[child + 1])
		{
			++child;
		}

		if (array[child] > array[last])
		{
			Swap(&array[child], &array[last]);
			last = child;
			child = 2 * last + 1;
		}
		else { return; }
	}
}
//������
void HeapSort(int* array, int size)
{
	int last = (size - 2) / 2;
	for (; last >= 0; --last)
	{
		AdjustDown(array, size, last);
	} 

	//��ɾ��
	int end = size - 1;
	while (end)
	{
		Swap(&array[end], &array[0]);
		AdjustDown(array, end,0);
		end--;
	}
}


//��������----ð������
void BubbleSort(int *array, int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = 1; j < size-i; ++j)
		{
			if (array[j-1] > array[j])
			{
				Swap(&array[j-1], &array[j]);
			}
		}
	}
}

//��������----ð��������Ż�
void BubbleSort2(int *array, int size)
{
	
	for (int i = 0; i < size - 1; ++i)
	{
		int ischange = 0;
		for (int j = 1; j < size - i; ++j)
		{
			if (array[j - 1] > array[j])
			{
				Swap(&array[j - 1], &array[j]);
				ischange = 1;
			}
		}
		if (!ischange)
		{
			return;
		}
	}
}
//==========================================================================

//��������ȡ��׼ֵ���Ż�
int GetMiddleIdx(int* array, int left, int right)
{
	int mid = (left + right) / 2;

	if (array[left] < array[right-1])
	{
		if (array[mid] < array[left])
			return left;

		else if (array[mid] > array[right-1])
			return right-1;

		else
			return mid;
	}

	else
	{
		if (array[mid] > array[left])
			return left;
		else if (array[mid] < array[right - 1])
			return right - 1;
		else
			return mid;
	}
}

int Partion1(int* array, int left, int right)
{
	int middle = GetMiddleIdx(array, left, right);
	if (middle != right - 1)
	{
		Swap(&array[middle], &array[right - 1]);
	}
	
	int key = array[right - 1];
	int begin = left;
	int end = right - 1;
	while (begin < end)
	{
		while (begin<end && array[begin] <= key)
		{
			++begin;
		}
		while (begin<end && array[end] >= key)
		{
			--end;
		}

		if (begin<end)
		{
			Swap(&array[end], &array[begin]);
		}
	}

	if (begin != right - 1)
	{
		Swap(&array[end], &array[right - 1]);
	}

	return begin;
}

//�ڿ�
int Partion2(int *array, int left, int right)
{
	int key = array[right - 1];
	int begin = left;
	int end = right - 1;

	while (begin < end)
	{
		while (begin < end && array[begin] <= key)
		{
			begin++;
		}

		if (begin < end)
		{
			array[end] = array[begin];
			end--;
		}

		while (begin < end && array[end] >= key)
		{
			--end;
		}

		if (begin < end)
		{
			array[begin] = array[end];
			begin++;
		}
	}
	array[begin] = key;
	return begin;

}

int	Partion3(int *array, int left, int right)
{
	int key = array[right - 1];
	int cur = left;
	int pre = cur - 1;

	while (cur < right)
	{
		if (array[cur] < key && ++pre != cur)
		{
			Swap(&array[cur], &array[pre]);
		}
		cur++;
	}
	if (++pre != right - 1)
	{
		Swap(&array[pre], &array[right - 1]);
	}
	return pre;
}

//��������---���¿��
//���һ�����нӽ�����---���ʺ��ÿ�������----�ò��뷨ȥ����
//�����������ѳ���--����Խ���Խ��~~~
void QuickSort(int* array, int left, int right)
{
	if (right - left <= 1)
	{
		return;
	}
	
	//div��һ���±�
	int div = Partion3(array, left, right);//��׼ֵ����
	QuickSort(array, left, div);
	QuickSort(array, div + 1, right);
}

//#include <stack>	s;
//void QuickSortNor(int* array, int size)
//{
//
//	int left = 0;
//	int right = size;
//
//	stack s;
//	stackInit(&s);
//	stackpush(&s, right);
//	stackpush(&s, left);
//
//	while (!StackEmpty(&s))
//	{
//		left = StackTop(&s);
//		StackPop(&s);
//		right = StackTop(&s);
//		StackPop(&s);
//
//		if (left < right)
//		{
//			int div = Partion3(array, left, right);
//			StackPush(&s,right);
//			StackPush(&s, div + 1);
//			StackPush(&s, div);
//			Stackpush(&s, left);
//			//div �����[left,div)
//			//div ���Ҳ�[div+1,right)
//		}
//	}
//	StackDestrony(&s);
//}
//===========================================================================

//�鲢
void MergeData(int *array, int left, int mid, int right,int *temp)
{
	int begin1 = left, end1 = mid;
	int begin2 = mid, end2 = right;

	int index = left;

	while (begin1 < end1 && begin2<end2)
	{
		if (array[begin1] < array[begin2])
		{
			temp[index++] = array[begin1++];
		}
		else
		{
			temp[index++] = array[begin2++];
		}
	}

	while (begin1 < end1)
	{
		temp[index++] = array[begin1++];
	}

	while (begin2 < end2)
	{
		temp[index++] = array[begin2++];
	}
}

//�ռ临�Ӷ�O(N)
void _MergeSort(int* array, int left, int right,int* temp)
{
	if (right - left <= 1)
	{
		return;
	}

	int mid = (left+right)/2;
	_MergeSort(array, left, mid,temp);
	_MergeSort(array, mid, right,temp);
	MergeData(array, left, mid, right, temp);
	memcpy(array + left, temp + left, sizeof(array[left]) * (right - left));
}

void MergeSort(int* array, int size)
{
	int* temp = (int*)malloc(size * sizeof(array[0]));
	if (temp == NULL)
	{
		assert(0);
		return;
	}

	_MergeSort(array, 0, size, temp);
	free(temp);
}

//===========================================================================
//�鲢ѭ��
void MergeSortNor(int* array, int size)
{
	int* temp = (int*)malloc(size * sizeof(array[0]));
	if (NULL == temp)
	{
		assert(0);
		return;
	}

	int gap = 1;
	while (gap<size)
	{
		for (int i = 0; i < size; i += 2 * gap)
		{
			int left = i;
			int mid = left + gap;
			int right = mid + gap;
			
			if (mid >= size)
			{
				mid = size;
			}

			if (right >= size)
			{
				right = size;
			}

			MergeData(array, left, mid, right, temp);
		}

		memcpy(array, temp, sizeof(array[0])*size);
		gap *= 2;
	}
	free(temp);
}

//=====================================================================
//�����ܼ�������ĳ����Χ��
void CountSort(int *array, int size)
{
	//ѡ����С�ĺ��������֡�O��N��	N����������ݸ���
	int MaxValue = array[0];
	int MinValue = array[0];

	for (int i = 1; i < size; ++i)
	{
		if (array[i] > MaxValue)
		{
			MaxValue = array[i];
		}
	
		if (array[i] < MinValue)
		{
			MinValue = array[i];
		}
	}

	//����ռ䡤O��M��[�����ռ�]��M���������ݷ�Χ
	int Range = MaxValue - MinValue + 1;
	int* array2 = (int*)malloc(sizeof(int)*Range);
	if (array2 == NULL)
	{
		assert(0);
		return;
	}
	
	//��ÿһ��λ���ÿ�
	memset(array2, 0, sizeof(int)*Range);

	//ͳ��Ԫ�س��ִ�����O(N)
	for (int i = 0; i < size; ++i)
	{
		array2[array[i]-MinValue]++;
	}

	//��������Ԫ�ء�O��N��
	int index = 0;
	for (int i = 0; i < Range; ++i)
	{
		while (array2[i]--)
		{
			array[index++] = i + MinValue;
		}
	}

	free(array2);
}


void printSort(int* array, int size)
{
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}


void Test()
{
	int array[] = { 0,9,7,1,4,3,6,2,8,5 };
	int len = sizeof(array) / sizeof(array[0]);
	printSort(array, len);
	//InsertSort2(array, len);
	//ShellSort(array, len);
	//SelectSort2(array, len);
	//BubbleSort2(array, len);
	//HeapSort(array, len);
	//QuickSortNor(array, len);
	//BubbleSort(array, len);
	/*MergeSort(array, len);*/
	//MergeSortNor(array, len);
	CountSort(array, len);
	//MergeSortNor(array, len);
	//QuickSort(array, 0,len);
	printSort(array, len);
}

