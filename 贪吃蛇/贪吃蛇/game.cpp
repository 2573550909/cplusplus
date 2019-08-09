#include<stdio.h>
#include<string.h>
#include<Windows.h>
#include<time.h>
#include<conio.h>


#define up 'w'
#define down 's'
#define left 'a'
#define right 'd'
#define stop 'p'

void welcome();               //55��ʼ����
void Finish();                //291��������
void creatgraph();            //69Χǽ��ӡ
void gotoxy(int x, int y);    //111�����ת����ΪX 0,1,2..
void gotoprint(int x, int y); //121��ת��ӡ
void gotodelete(int x, int y);//127��תɾ��
void creatfood();             //133ʳ�����
int ClickControl();           //157��ȡ�����ź�
int Judge();                  //270��Ϸ�����ж�
void MovingBody();      //172�ߵ��ƶ� 
void Eating();                //223�߳Ե�������Ĳ������쳤��
void ChangeBody(int a, int b); //245�ߵ�����任,��һ������ǰһ��STRUCT,a,bΪhead֮ǰ���� 

/*ȫ�ֱ��� + Ԥ����*/
typedef struct Snakes
{
	int x;
	int y;
	struct Snakes *next;
}snake;

snake *head, *tail;

struct Food
{
	int x;
	int y;
}food;
char name[20];
int score = 0;
char click = 1;
int speed;

/************************************************************/

int main()
{
	system("color 0B");
	welcome();
	creatgraph();
	creatfood();
	if (ClickControl() == 0) return 0;
	return 0;
}

/**********************************************************/
void welcome()
{
	gotoxy(15, 10);
	printf("/**********************************************/");
	gotoxy(15, 20);
	printf("/**********************************************/");
	gotoxy(20, 13);
	printf("WELCOME TO THE GAME OF RETRO SNAKE");
	gotoxy(14, 16);
	printf("����Ӣ�����뷨�в����������ƶ���ͬ�ڳԵ��Լ���wasd����p��ͣ");
	gotoxy(20, 18);
	printf("PLEASE ENTER YOUR NAME:");
	scanf_s("%s", &name, 10);
	system("cls");
}
/**********************************************************/
void creatgraph()
{
	int i;
	for (i = 0; i < 58; i += 2)//��ӡ���±߿�
	{
		gotoprint(i, 0);
		gotoprint(i, 26);
	}
	for (i = 1; i < 26; i++)
	{
		gotoprint(0, i);
		gotoprint(56, i);
	}
	gotoxy(63, 10);
	printf("hello %s,Welcome To Play", name);
	gotoxy(63, 15);
	printf("Your Score Is:%d    =���أ�= ", score);
	gotoxy(63, 20);
	printf("This Game Is Created By JOKER");
	head = (snake*)malloc(sizeof(snake));
	head->x = 16;
	head->y = 15;
	//gotoprint(head->x, head->y);
	tail = (snake*)malloc(sizeof(snake));
	snake *p = (snake*)malloc(sizeof(snake));
	snake *q = (snake*)malloc(sizeof(snake));
	p->x = 16;
	p->y = 16;
	q->x = 16;
	q->y = 17;
	head->next = p;
	p->next = q;
	q->next = tail;
	//gotoprint(p->x, p->y);
	//gotoprint(q->x, q->y);
	tail->next = NULL;
	tail->x = 4;
	tail->y = 2;

}

void gotoxy(int x, int y)
{
	COORD pos;
	HANDLE hOutput;
	pos.X = x;
	pos.Y = y;
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput, pos);
}
/**********************************************************/
void gotoprint(int x, int y)
{
	gotoxy(x, y);
	printf("��");
}
/**********************************************************/
void gotodelete(int x, int y)
{
	gotoxy(x, y);
	printf("  ");
}
/**********************************************************/
void creatfood()
{
	srand((int)time(NULL));
lable:
	food.y = rand() % (25 - 1 + 1) + 1;
	food.x = rand() % (54 - 2 + 1) + 2;
	if (food.x % 2 != 0)
	{
		food.x = food.x + 1;
	}
	snake *judge = head;
	while (1)  //�����ų������ظ�
	{
		if (judge->next == NULL) break;
		if (food.x == judge->x&&food.y == judge->y)
		{
			goto lable;
		}
		judge = judge->next;
	}
	gotoxy(food.x, food.y);
	printf("��");
}
/**********************************************************/
int ClickControl()
{
	char c;
	while (1)
	{
		if (Judge() == 0) return 0;
		if (_kbhit())
		{
			click = _getch();
		}
		MovingBody();
		Eating();
	}
	return 1;
}
/**********************************************************/
void MovingBody()
{
	int count = 0;
	int a = head->x, b = head->y;
	snake *p = head;
	//ͨ������պ��ӡʵ�ֶ���Ч��
	while (1)
	{
		if (p->next == NULL) break;
		gotodelete(p->x, p->y);
		count++;
		p = p->next;
	}
	switch (click)
	{
	case up:
		head->y -= 1;
		ChangeBody(a, b);
		break;
	case down:
		head->y += 1;
		ChangeBody(a, b);
		break;
	case left:
		head->x -= 2;
		ChangeBody(a, b);
		break;
	case right:
		head->x += 2;
		ChangeBody(a, b);
		break;
	case stop:
		_getch();
		break;
	}
	p = head;
	while (1)
	{
		if (p->next == NULL) break;
		gotoprint(p->x, p->y);
		p = p->next;
	}
	p = head;
	gotoxy(0, 28);
	if (count <= 10) speed = 150;
	else if (count > 10 && count <= 20) speed = 100;
	else if (count > 20 && count <= 40) speed = 50;
	else speed = 10;
	Sleep(speed);
}

void Eating()
{
	if (head->x == food.x&&head->y == food.y)
	{
		creatfood();
		snake *_new = (snake*)malloc(sizeof(snake));
		snake *p;
		p = head;
		while (1)
		{
			if (p->next->next == NULL) break;
			p = p->next;
		}
		p->next = _new;
		_new->next = tail;
		score += 10;
		gotoxy(77, 15);
		printf("%d", score);
	}
}
/**********************************************************/
void ChangeBody(int a, int b)
{
	snake *p = head->next;
	int mid1, mid2, _mid1, _mid2;
	mid1 = p->x;
	mid2 = p->y;
	while (1)
	{
		if (p->next->next == NULL) break;
		_mid1 = p->next->x;
		_mid2 = p->next->y;
		p->next->x = mid1;
		p->next->y = mid2;
		mid1 = _mid1;
		mid2 = _mid2;
		p = p->next;
	}
	p = head->next;
	//if (p->next!= NULL)
	{
		p->x = a;
		p->y = b;
	}
}
/**********************************************************/
int Judge()
{
	if (head->x == 0 || head->x == 56 || head->y == 0 || head->y == 26)
	{
		Finish();
		return 0;
	}
	snake *p = head->next;
	while (1)
	{
		if (p->next == NULL) break;
		if (head->x == p->x&&head->y == p->y)
		{
			Finish();
			return 0;
		}
		p = p->next;
	}
	return 1;
}
/**********************************************************/
void Finish()
{
	system("cls");
	gotoxy(15, 10);
	printf("/**********************************************/");
	gotoxy(15, 20);
	printf("/**********************************************/");
	gotoxy(18, 14);
	printf("GAME   OVER      o(*������*)o");
	gotoxy(20, 16);
	printf("Your Score is %d    hiahiahia", score);
	gotoxy(18, 18);
	printf("������Ŷ��     ����Ŭ��O(��_��)O");
	gotoxy(0, 27);
	system("pause");
}
#include<conio.h>
#include<graphics.h>
#include <time.h>//�������ͷ�ļ�
#include<windows.h>
#include <stdlib.h>
#include <stdio.h>

#define N 4//��ʼ�߽ڵ����
#define S 260
typedef struct node
{
	int x;
	int y;
	struct node *next;
} snake; //��������Ľṹ��

int food[5] = { 200,200 }; //ʳ������food[0],food[1]
int re_food[5];
int live = 1;//�����ߵ�����
int score = 0;
int speed = 210;
int s_dir = 3;//��ʼ�ƶ�����
//1,2,3,4�ֱ�����ߵ����ϣ��ң����ĸ��ƶ�����
int index;
int temp = 0;
int flag = 0;
//����һ���ߣ�����
snake *Creat_node(){
	int num = N;
	int n = S;
	snake *head = NULL, *tail = NULL, *p;
	while (num--){
		p = (snake *)malloc(sizeof(snake));
		p->x = n;
		n -= 20;
		p->y = S;
		p->next = NULL;
		if (head == NULL)
			head = p;
		else
			tail->next = p;
		tail = p;
	}
	return head;
}
//�������ʳ��
void appear_food(snake *head)
{
	snake *p = head;
loop:
	srand(time(0));//�趨���������
	food[0] = rand()%1100+1;
	food[1] = rand()%600+1;
	while (food[0] % 20 != 0)//ʳ��������ֺ������ʳ���ܹ���������,�����ſ������߳Ե�
		food[0]++;
	while (food[1] % 20 != 0)
		food[1]++;
	//�����Ƿ���������λ��һ��
	while (p != NULL)
	{
		if (p->x == food[0] && p->y == food[1])
			goto loop;
		p = p->next;
	}
}
//�Ӽ��̻�ȡ���룬���ߵ��ƶ�����
void get_input()
{
	char key;
	if (kbhit())
	{
		key = getch();//���ն�Ӧ��ASCII��
		switch (key)
		{
		case 37://��
			if (s_dir != 3)
				s_dir = 1;
			break;
		case 38://��
			if (s_dir != 4)
				s_dir = 2;
			break;
		case 39://��
			if (s_dir != 1)
				s_dir = 3;
			break;
		case 40://��
			if (s_dir != 2)
				s_dir = 4;
			break;
		case 27://Esc(�˳�)
			s_dir = 27;
			break;
		case 32://�ո�(��ͣ)
			s_dir = 32;
			break;
		default:
			break;
		}
	}
}
//
//
////�ߵ��ƶ�
snake *_move(snake *head)
{
	snake *str, *ptr, *ptr2;
	int m, n;
	m = head->x;
	n = head->y;
	switch (s_dir)
	{
	case 1:
		m -= 20;
		break;
	case 2:
		n -= 20;
		break;
	case 3:
		m += 20;
		break;
	case 4:
		n += 20;
		break;
	default:
		break;
	}
	str = (snake *)malloc(sizeof(snake));
	str->x = m;
	str->y = n;
	str->next = head;
	head = str;
	ptr = head->next->next;
	while (ptr != NULL)
	{
		if (ptr->x == str->x&&ptr->y == str->y)
		{
			live = 0;
			return str;
		}
		ptr = ptr->next;
	}
	if (str->x <= -1 || str->x >= 1190 || str->y <= -1 || str->y >= 690)
	{
		live = 0;
		return str;
	}
	if (str->x == food[0] && str->y == food[1])
	{
		score += 2;
		if (score > 28 && speed < 300)
			speed += 5;

		setfillcolor(BLACK);
		bar(food[0], food[1], food[0] + 20, food[1] + 20);
		appear_food(str);
	}
	else
	{
		ptr = ptr2 = str;
		while (ptr->next != NULL)
		{
			ptr2 = ptr;
			ptr = ptr->next;
		}
		ptr2->next = NULL;
		setfillcolor(BLACK);
		bar(ptr->x, ptr->y, (ptr->x) + 20, (ptr->y) + 20);
		free(ptr);
	}
	return head;
}
//��ͼ�ν���
void draw_interface(snake *head)
{
	snake *p = head;
	printf("score:%d  speed:%d", score, speed);
	setfillcolor(YELLOW);
	bar(food[0], food[1], food[0] + 20, food[1] + 20);
	while (p != NULL)
	{
		if (p == head)
		{
			setfillcolor(LIGHTGREEN);
			bar(p->x, p->y, (p->x) + 20, (p->y) + 20);
			setfillcolor(BLACK);
			circle((p->x) + 10, (p->y) + 10, 3);
		}
		else
		{
			setfillcolor(GREEN);
			bar(p->x, p->y, (p->x) + 20, (p->y) + 20);
		}
		p = p->next;
	}
}


//void reward_food(snake *head)
//{
//	snake *p = head;
//loop:
//	srand(time(0));//�趨���������
//	re_food[0] = rand()%1100+1;
//	re_food[1] = rand()%600+1;
//	while (re_food[0] % 20 != 0)//ʳ��������ֺ������ʳ���ܹ���������,�����ſ������߳Ե�
//		re_food[0]++;
//	while (re_food[1] % 20 != 0)
//		re_food[1]++;
//	//�����Ƿ���������λ��һ��
//	while (p != NULL)
//	{
//		if (p->x == re_food[0] && p->y == re_food[1])
//			goto loop;
//		p = p->next;
//	}
//	if (re_food[0] == food[0] && re_food[1] == food[1])
//		goto loop;
//	setfillcolor(RED);
//	bar(re_food[0], re_food[1], re_food[0] + 20, re_food[1] + 20);
//}
//
//
//int main()
//{
//	FILE *fp;
//	int max_score = 0;
//	fp = fopen("record", "r");
//	fscanf(fp, "%d", &max_score);
//	fclose(fp);
//	snake *head = NULL, *p = head, *ptr = head;
//	char n;
//	int dir;
//	initgraph(1200, 700);
//	setbkcolor(BLACK);
//	setfont(100, 0, "����");
//	setcolor(RED);
//	//setfontbkcolor(BLACK);
//	outtextxy(350, 200, "̰  ��  ��");
//	setfont(40, 0, "����");
//	setcolor(WHITE);
//	//setfontbkcolor(BLACK);
//	outtextxy(350, 410, "����Enter����ʼ");
//	outtextxy(350, 490, "�����ո���ͣ ��Esc���˳�");
//	outtextxy(350, 570, "����������ƶ�����---");
//loop:
//	n = getch();
//	if (n == 13)
//	{
//		cleardevice();
//		head = Creat_node();
//		while (1)
//		{
//			dir = s_dir;
//			while (!kbhit())
//			{
//				Sleep(300 - speed);
//				head = _move(head);
//				if (live == 0)
//					break;
//				draw_interface(head);
//			}
//			get_input();
//			if (s_dir == 27)
//				break;
//			if (s_dir == 32)
//			{
//			lap:
//				n = getch();
//				if (n == 32)
//					s_dir = dir;
//				else if (n == 27)
//					break;
//				else
//					goto lap;
//			}
//			head = _move(head);
//			if (live == 0)
//				break;
//			draw_interface(head);
//			srand(time(0));
//			index = rand()%5000+1;
//			if (index % 35 == 0 && flag == 0)
//			{
//				flag = 1;
//				reward_food(head);
//			}
//			if (flag == 1)
//			{
//				if (head->x == re_food[0] && head->y == re_food[1])
//				{
//					setfillcolor(BLACK);
//					bar(re_food[0], re_food[1], re_food[0] + 20, re_food[1] + 20);
//					if (head->next->next != NULL)
//					{
//						ptr = head;
//						setfillcolor(BLACK);
//						bar(ptr->x, ptr->y, (ptr->x) + 20, (ptr->y) + 20);
//						head = head->next;
//						free(ptr);
//					}
//					temp = 0;
//					flag = 0;
//				}
//				else
//				{
//					temp++;
//					if (temp == 6)
//					{
//						setfillcolor(BLACK);
//						bar(re_food[0], re_food[1], re_food[0] + 20, re_food[1] + 20);
//						flag = 0;
//						temp = 0;
//					}
//				}
//			}
//			Sleep(100);
//		}
//	}
//	else if (n == 27)
//	{
//		closegraph();
//		return 0;
//	}
//	else
//		goto loop;
//	Sleep(500);
//	cleardevice();
//	setfont(100, 0, "����");
//	setcolor(RED);
//	//setfontbkcolor(BLACK);
//	outtextxy(300, 250, "�� Ϸ �� ��");
//	Sleep(2000);
//	cleardevice();
//	setbkcolor(YELLOW);
//	setfont(70, 0, "����");
//	setcolor(BLACK);
//	printf("�� �� �� �� : %d", score);
//	while (head != NULL)
//	{
//		p = head;
//		head = head->next;
//		free(p);
//	}
//	Sleep(2000);
//	if (score > max_score)
//	{
//		cleardevice();
//		setfont(70, 0, "����");
//		setcolor(BLACK);
//		outtextxy(250, 250, "  ��ϲ�����Ƽ�¼��");
//		fp = fopen("record", "w");
//		fprintf(fp, "%d", score);
//		fclose(fp);
//	}
//	getch();
//	closegraph();
//	system("pause");
//	return 0;
//}
