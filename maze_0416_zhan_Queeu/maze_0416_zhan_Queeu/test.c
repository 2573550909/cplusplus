////��ʲô��ʵ��ջ   ˳��� or ����
//
//typedef int SDataType;
//typedef struct Stack
//{
//	SDataType* _array;
//	int _capacity;
//	int _top; // ���ջ��λ�� 
//}Stack;
//
//// ��ʼ��ջ 
//void StackInit(Stack* ps)
//{
//	ps->_capacity = 10;
//	SDataType* _array = (SDataType*)malloc(sizeof(SDataType)*ps->_capacity);
//	
//}
//
//// ��ջ 
//void StackPush(Stack* ps, SDataType data)
//{
//
//}
//
//// ��ջ 
//void StackPop(Stack* ps);
//
//// ��ȡջ��Ԫ�� 
//SDataType StackTop(Stack* ps);
//
//// ��ȡջ����ЧԪ�ظ��� 
//int StackSize(Stack* ps);
//
//// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
//int StackEmpty(Stack* ps);
//
//// ����ջ 
//void StackDestroy(Stack* ps);
////4. ջ��Ӧ�ã�����ƥ�䡢�沨�����ʽ��ջ��ݹ�
////5. ��Ϥ���еĸ����Լ�����
////6. ��Ϥѭ�����У�������ѭ����������ж϶�����
////7. ʵ�ֶ��е����»�������
//typedef int * QDataType;
//
//// ��ʽ�ṹ����ʾ���� 
//typedef struct QListNode
//{
//	struct QListNode* _pNext;
//	QDataType _data;
//}	QNode;
//
//// ���еĽṹ 
//typedef struct Queue
//{
//	QNode* _front;
//	QNode* _rear;
//}Queue;
//
//// ��ʼ������ 
//void QueueInit(Queue* q)
//{
//	q->_front = q->_rear = NULL;
//}
//
//// ��β����� 
//void QueuePush(Queue* q, QDataType data);
//
//// ��ͷ������ 
//void QueuePop(Queue* q);
//
//// ��ȡ����ͷ��Ԫ�� 
//QDataType QueueFront(Queue* q);
//
//// ��ȡ���ж�βԪ�� 
//QDataType QueueBack(Queue* q);
//
//// ��ȡ��������ЧԪ�ظ��� 
//int QueueSize(Queue* q);
//
//// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
//int QueueEmpty(Queue* q);
//
//// ���ٶ��� 
//void QueueDestroy(Queue* q);
//
//
////=====================================================
////��̬˳���
//typedef struct Stack
//{
//	int array[100];
//	int size;
//}	Stack;
//
//void StackInit(Stack* s)
//{
//	s->size = 0;
//}
//
//void StackDestroy()
//{
//	s->szie = 0;
//}
//
////ѹ��
//void StackPush(Stack *s, int v)
//{
//	s->array[s->size++] = v;
//}
//
////����
//void StackPop(Stack *s, int v)
//{
//	s->size--;
//}
//
////����ջ����Ԫ�أ���ɾ��
//void StackTop2(Stack *s, int v)
//{
//	return s->array[s->size - 1];
//}
//
////����ջ�����ݸ���
//int StackSize(Stack *s, int v)
//{
//	return s->size;
//}
//
////�����Ƿ��ǿ�ջ
//int StackEmpty(Stack *s, int v)
//{
//	return !s->size;
//}
//
//
//
//
