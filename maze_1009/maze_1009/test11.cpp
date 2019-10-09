#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	vector<int>vec{ 1,2,3,4,5,6,7,8, };
	sort(vec.begin(), vec.end(), cmp);
	for (size_t i = 0; i < vec.size(); ++i) {
		cout << vec[i] << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}

#if 1
static bool cmp(int a, int b) {
	string A = "";
	string B = "";
	A += to_string(a);
	A += to_string(b);
	B += to_string(b);
	B += to_string(a);

	return A < B;
}

string PrintMinNumber(vector<int> numbers) {
	string  answer = "";
	sort(numbers.begin(), numbers.end(), cmp);
	for (int i = 0; i < numbers.size(); i++) {
		answer += to_string(numbers[i]);
	}
	return answer;
}


//static bool cmp(int a, int b) {
//	string A = "";
//	string B = "";
//	A += to_string(a);
//	A += to_string(b);
//	B += to_string(b);
//	B += to_string(a);
//
//	return A < B;
//}

string PrintMinNumber(vector<int> numbers) {
	string  answer = "";
	sort(numbers.begin(), numbers.end(), [](int a,int b) {
		string A = to_string(a);
		string B = to_string(a);
		return A + B < B + A;
	});
	for (int i = 0; i < numbers.size(); i++) {
		answer += to_string(numbers[i]);
	}
	return answer;
}
bool cmp(int a, int b) {
	string A = to_string(a);
	string B = to_string(b);
	return A > B;
}
string PrintMinNumber(vector<int> numbers) {
	string result = "";
	sort(numbers.begin(), numbers.end(), cmp);

	for (size_t i = 0; i < numbers.size(); i++) {
		result += to_string(numbers[i]);
	}
	return result;
}

int main() {
	vector<int> numbers{ 1,23,34,234 };
	//34234231
	// sort(numbers.begin(), numbers.end());
	//int a[10] = { 1,4,6,3,2,8,5,9,0 ,7 };
	//vector<int>v(a, a + 10);
	//sort(v.begin(), v.end());
	//for (auto&e : v) {
	//	cout << ' ' << endl;
	//}
	//cout << endl;
	cout << PrintMinNumber(numbers) << endl;
	//332321
	system("pause");
	return 0;
}
int main() {
	int n = 100;
	string str = to_string(n);
	cout << str << endl;

	system("pause");
	return 0;
}
//���ֵ����С�������� 
bool cmp(string a, string b) {
	return a + b < b + a; 
}

int main() {
	string numbers[3];
	numbers[0] = "3";
	numbers[1] = "32";
	numbers[2] = "321";
	sort(numbers, numbers + 3,cmp);
	string s = "";
	for (int i = 0; i < 3; ++i) {
		s += numbers[i];
	}
	cout << s << endl;
	//PrintMinNumber(numbers);
	system("pause");
	return 0;
}
bool cmp(string a, string b) {
	return a + b < b + a; 
}
string PrintMinNumber(vector<int> numbers) {
	string answer;

	int size = numbers.size();
	sort(numbers.begin(), numbers.end(), cmp);
	for (int i = 0; i < numbers.size(); i++) {
		answer += numbers[i];
	}
	return answer;
}


int main() {
	string s[3];
	s[0] = "b"; s[1] = "ba"; s[2] = "ab";
	sort(s, s + 3, cmp);

	string res = "";
	for (int i = 0; i < 3; i++){
		res += s[i];
	}
	cout << res << endl;;

	system("pause");
	return 0;
}

//���ֵ����С�������� 
bool cmp(string a, string b) {
	return a < b; 
}

string PrintMinNumber(vector<int> numbers) {
	string answer;

	int size = numbers.size();
	sort(numbers.begin(), numbers.end(), cmp);
	for (int i = 0; i < numbers.size(); i++) {
		answer += numbers[i];
	}
	return answer;
}

int main() {
	vector<int>numbers{ '3','32','321' };
	PrintMinNumber(numbers);

	system("pause");
	return 0;
}

int NumberOf1Between1AndN_Solution(int n) {
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 2;
	}
	int count = 0;
	for (int i = 1; i <= n; ++i) {
		int j = i;
		while (j) {
			if (j % 10 == 1) {
				count += 1;
			}
			j = j / 10;
		}
	}
	return count;
}

int main() {
	cout << NumberOf1Between1AndN_Solution(10000)-1<< endl;

	system("pause");
	return 0;
}

int NumberOf1Between1AndN_Solution(int n){
	/* ��Ҫ˼·���趨�����㣨��1��10��100�ȵȣ�
	��Ϊλ�õ�i����Ӧn�ĸ�λ��ʮλ����λ�ȵȣ�
	�ֱ��ÿ����λ���ж��ٰ���1�ĵ���з���
	�����趨������λ�ã���n���зָ��Ϊ�����֣���λn/i����λn%i
	��i��ʾ��λ���Ұ�λ��Ӧ����>=2,��n=31456,i=100��
		��a=314,b=56����ʱ��λΪ1�Ĵ�����a/10+1=32�������λ0~31����
		ÿһ�ζ�����100�������ĵ㣬������(a%10+1)*100����İ�λΪ1
	��i��ʾ��λ���Ұ�λ��Ӧ����Ϊ1����n=31156,i=100��
		��a=311,b=56����ʱ��λ��Ӧ�ľ���1��
		����a%10(�����λ0-30)���ǰ���100�������㣬
		�������λΪ31����a=311��������ֻ��Ӧ�ֲ���00~56����b+1�Σ�
		���е���������У�a%10*100��+(b+1)����Щ���λ��ӦΪ1
	��i��ʾ��λ���Ұ�λ��Ӧ����Ϊ0,��n=31056,i=100��
		��a=310,b=56����ʱ��λΪ1�Ĵ�����a/10=31�������λ0~30��

	�ۺ������������������λ��Ӧ0��>=2ʱ����(a+8)/10�ΰ�������100���㣬
	���е���λΪ1(a%10==1)����Ҫ���Ӿֲ���b+1
	֮���Բ�8������Ϊ����λΪ0����a/10==(a+8)/10��
	����λ>=2����8�������λλ��Ч����ͬ��(a/10+1)
	*/

	int count = 0;
	long long i = 1;
	for (i = 1; i <= n; i *= 10){
		int a = n / i;
		int b = n % i;
		// a % 10 == 1��*��b+1��������������λ����Ϊ1����Ҫ�ӵ�λ������
		count = count + (a + 8) / 10 * i + (a % 10 == 1)*(b + 1);
	}
	return count;
}
};
vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
	int len = input.size();
	if (len <= 0 || k > len) return vector<int>();
	//�º����е�greater<T>ģ�壬�Ӵ�С����
	multiset<int, greater<int> > leastNums;
	vector<int>::iterator vec_it = input.begin();
	for (; vec_it != input.end(); vec_it++) {
		//��ǰk��Ԫ�ز��뼯��
		if (leastNums.size() < k) {
			leastNums.insert(*vec_it);
		}
		else {
			//��һ��Ԫ�������ֵ
			multiset<int, greater<int> >::iterator greatest_it = leastNums.begin();
			//�������Ԫ��<��һ��Ԫ�أ�ɾ����һ�������뵱ǰԪ��
			if (*vec_it < *(leastNums.begin())) {
				leastNums.erase(greatest_it);
				leastNums.insert(*vec_it);
			}
		}
	}
	return vector<int>(leastNums.begin(), leastNums.end());
}

int main() {

	system("pause");
	return 0;
}
#endif
