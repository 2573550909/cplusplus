//#include <stdio.h>
//#include <stdlib.h>
//#include <assert.h>
////1. ��Ϥ˳���ĸ���
////2. ��Ϥ˳���ķ��ࣿ��̬˳���Ͷ�̬˳��������
////3. ʵ�ֶ�̬˳�������»���������
//typedef int DataType;
//
//typedef struct SeqList
//{
//	DataType* _array; // ����˳�������ЧԪ�ظ��� 
//	int _capacity; // �ռ��ܴ�С 
//	int _size; // ��ЧԪ�ظ��� 
//}SeqList, *PSeqList;
//
////��ʼ��˳���
//void SeqListInit(PSeqList ps)
//{
//	assert(ps != NULL);
//	ps->_capacity = 10;//����
//	//���ٿռ�
//	ps->_array = (int*)malloc(sizeof(DataType)*ps->_capacity);
//	//sizeΪ��Ч����,�������Ϊ0
//	ps->_size = 0;
//}
//
//void SeqListDestroy(PSeqList ps)
//{
//	ps->_size = 0;
//	ps->_capacity = 0;
//	free(ps->_array);
//}
//
//// β�� 
//void SeqListPushBack(PSeqList ps, DataType data)
//{
//	ps->_array[ps->_size] = data;
//	ps->_size++;
//}
//// βɾ 
//void SeqListPopBack(PSeqList ps)
//{
//	ps->_size--;
//}
//
//// ͷ�� 
//void SeqListPushFront(PSeqList ps, DataType data)
//{
//	assert(ps);
//	ps->_size++;
//	for (int i = 0; i < ps->_size; ++i)
//	{
//		ps->_array[i+1] = ps->_array[i];
//	}
//	ps->_array[0] = data;
//}
//
//// ͷɾ 
//void SeqListPopFront(PSeqList ps)
//{
//	if()
//
//}
//
//// ����λ�ò��� 
//void SeqListInsert(PSeqList ps, int pos, DataType datda);
//
//// ����λ��ɾ�� 
//void SeqListErase(PSeqList ps, int pos);
//
//// ���data�ͷ���˳����� 
//int SeqListFind(PSeqList ps, DataType data);
//
//// �Ƴ�˳����е�һ��ֵΪdata��Ԫ�� 
//void SeqListRemove(PSeqList ps, DataType data);
//
//// �Ƴ�˳���������ֵΪdata��Ԫ�� 
//void SeqListRemoveAll(PSeqList ps, DataType data);
//
//// ��ȡ˳�����ЧԪ�ظ��� 
//int SeqListSize(PSeqList ps);
//
//// ��ȡ˳�������� 
//int SeqListCapacity(PSeqList ps);
//
//// ���˳����Ƿ�Ϊ�� 
//int SeqListEmpty(PSeqList ps);
//
//// ��ȡ˳����е�һ��Ԫ�� 
//DataType SeqListFront(PSeqList ps);
//
//// ��ȡ˳��������һ��Ԫ�� 
//DataType SeqListBack(PSeqList ps);
//
////4. ��Ϥ˳������ȱ��
