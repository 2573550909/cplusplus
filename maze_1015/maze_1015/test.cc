#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <stack>
#include <vector>
#include <string>
#include <regex>
#include <assert.h>
#include <string>
using namespace std;

#if 0
class Object;
class SmartPointer;

// ����ָ����һ����Դ�����࣬ͨ����ԭʼָ��ķ�װ��
// ����Դ������������������ʱ���ָ��ָ����ڴ�
// �����ͷţ�ͨ��ʹ�����ü�����ʽ���й���

class Counter {
	friend class SmartPointer;
public:
	Counter() {
		ptr = nullptr;
		cnt = 0;
	}
	Counter(Object*p) {
		ptr = p;
		cnt = 1;
	}
	~Counter() {
		delete ptr;
	}
private:
	Object*ptr;
	int cnt;
};

class SmartPointer {
public:
	SmartPointer(Object* p) {
		ptr_counter = new Counter(p);
	}
	SmartPointer(const SmartPointer&sp) {
		ptr_counter = sp.ptr_counter;
		++ptr_counter->cnt;
	}
	SmartPointer& operator = (const SmartPointer& sp) {
		++sp.ptr_counter->cnt;
		--ptr_counter->cnt;
		if (ptr_counter->cnt == 0) {
			delete ptr_counter;
		}
		ptr_counter = sp.ptr_counter;
	}
	~SmartPointer() {
		--ptr_counter->cnt;
		if (ptr_counter->cnt == 0) {
			delete ptr_counter;
		}
	}
private:
	Counter* ptr_counter;
};


bool duplicate(int numbers[], int length, int* duplication) {
	// 2,3,1,0,2,5,3 
	for (int i = 0; i < length; ++i) {
		int index = numbers[i] % length;
		if (numbers[index] >= length) {
			*duplication = index;
			return true;
		}
		numbers[index] += length;
	}
	return false;
}

int find_dup(int numbers[], int length) {
	// 2,3,1,0,2,5,3 
	for (int i = 0; i < length; i++) {
		int index = numbers[i];
		if (index >= length) {
			index -= length;
			return index;
		}
		numbers[index] += length;
	}
	return -1;
}
#endif

#if 0
vector<int> multiply(const vector<int>& A) {
	vector<int>B;
	if (A.empty()) {
		return B;
	}
	for (int i = 0; i < A.size(); ++i) {
		int temp = 1;
		for (int j = 0; j < A.size(); ++j) {
			if (i == j && j < A.size()-1) {
				++j;
			}
			temp *= A[j];
		}
		B.push_back(temp);
	}
	return B;
}
#endif

void multiply(const vector<double>&array1, vector<double>& array2) {
	int length1 = array1.size();
	int length2 = array2.size();

	if (length1 == length2 && length2 > 1) {
		array2[0] = 1;
		for (int i = 1; i < length1; ++i) {
			array2[i] = array2[i - 1] * array1[i - 1];
		}
		double temp = 1;
		for (int i = length1 - 2; i >= 0; --i) {
			temp *= array1[i + 1];
			array2[i] *= temp;
		}
	}
}

int main() {
	const vector<double>A{ 1,2,3,4,5};
	vector<double>B{ 1,1,1,1,1};
	multiply(A,B);

	system("pause");
	return 0;
}

//1���ھ�����Ҫ���������ϣ����Լӿ��������ٶȡ� 
//2������Ϊ���������ϣ�ǿ�Ƹ��е�Ψһ�Ժ���֯�������ݵ����нṹ��
//3���ھ��������������ű�����ϣ���Щ����Ҫ��һЩ�����
//   ���Լӿ����ӵ��ٶȡ�
//4���ھ�����Ҫ���ݷ�Χ�������������ϴ���������
//   ��Ϊ�����Ѿ�������ָ���ķ�Χ�������ġ�
//5���ھ�����Ҫ��������ϴ�����������Ϊ�����Ѿ�����
//   ������ѯ�����������������򣬼ӿ������ѯʱ�䡣
//6���ھ���ʹ����WHERE�Ӿ��е������洴���������ӿ��������ж��ٶȡ�


//int StrToInt(string str) {
//	if (str.empty()) {
//		return 0;
//	}
//	int symbol = 1;
//	//������
//	if (str[0] == '-') {
//		symbol = -1;
//		str[0] = '0';
//		//�����ǡ�0�� ����0
//	}
//	//��������
//	else if (str[0] == '+') {
//		symbol = 1;
//		str[0] = '0';
//	}
//	long long  sum = 0;
//	for (int i = 0; i < str.size(); ++i) {
//		if (str[i] < '0' || str[i] > '9') {
//			sum = 0;
//			break;
//		}
//		sum = sum * 10 + str[i] - '0';
//		if (sum > 2147483647) {
//			return 0;
//		}
//	}
//	return symbol * sum;
//}
//
//int StrToInt(string str) {
//	if (str.empty()) {
//		return 0;
//	}
//	int symbol = 1;
//	//������
//	if (str[0] == '-') {
//		symbol = -1;
//		str[0] = '0'; 
//		//�����ǡ�0�� ����0
//	}
//	//��������
//	else if (str[0] == '+') {
//		symbol = 1;
//		str[0] = '0';
//	}
//	int sum = 0;
//	for (int i = 0; i < str.size(); ++i) {
//		if (str[i] < '0' || str[i] > '9') {
//			sum = 0;
//			break;
//		}
//		sum = sum * 10 + str[i] - '0';
//	}
//	if (sum < INT_MIN || sum > INT_MAX) {
//		return 0;
//	}
//	return symbol * sum;
//}
//
//
//int StrToInt(string str) {
//	if (str.empty()) {
//		return 0;
//	}
//
//	// ����ַ���������������zhengfuΪ true;
//	// ����� '+' ��zheΪtrue
//	// ����� '-' ��zheΪfalse
//	bool zhengfu = false;
//	bool zhe = true;
//	if (str[0] == '-' ||str[0] =='+') {
//		zhengfu = true;
//		if(str[0] == '-'){
//			zhe = false;
//		}
//	}
//
//	//�ַ�תʮ���Ƶ���
//	bool nul = true;
//	// nul ��ʾ�ַ����Ƿ���Ч��Ĭ��Ϊ��Ч
//	int size = str.size();
//	int n = size;
//	long long num = 0;
//
//	//Ϊ��������һ���ַ�
//	int j = 0;
//	if (zhengfu) {
//		j = 1;
//	}
//	for (int i = j; i < str.size(); ++i) {
//		if (str[i] >= '0' && str[i] <= '9') {
//			long long a = pow(10, size - 1);
//			num += (str[i] - '0')*a;
//			--size;
//		}
//		else {
//			nul = false;
//			break;
//		}
//	}
//	// �ַ�����Чֱ�ӷ���0 
//	if (!nul) {
//		return 0;
//	}
//	if (num / 10 == 2147483648) {
//		return 0;
//	}
//	//��������� �򷵻ص�ֵ/10
//	if (zhengfu && zhe) {
//		return num/10;
//	}
//	if (!zhengfu && zhe) {
//		return num;
//	}
//	if (zhengfu && !zhe) {
//		return -(num / 10);
//	}
//	if (!zhengfu && zhe) {
//		-num;
//	}
//}
//

//int StrToInt(string str) {
//	if (str.empty()) {
//		return 0;
//	}
//	int symbol = 1;
//	//������
//	if (str[0] == '-') {
//		symbol = -1;
//		str[0] = '0';
//		//�����ǡ�0�� ����0
//	}
//	//��������
//	else if (str[0] == '+') {
//		symbol = 1;
//		str[0] = '0';
//	}
//	long long sum = 0;
//	for (int i = 0; i < str.size(); ++i) {
//		if (str[i] < '0' || str[i] > '9') {
//			sum = 0;
//			break;
//		}
//		sum = sum * 10 + str[i] - '0';
//		if (symbol && sum > 2147483647) {
//			return 0;
//		}
//		if (!symbol && sum > 2147483649) {
//			return 0;
//		}
//	}
//	return symbol * sum;
//}
//
int StrToInt(string str) {
	if (str.empty()) {
		return 0;
	}
	int symbol = 1;
	//������
	if (str[0] == '-') {
		symbol = -1;
		str[0] = '0';
		//�����ǡ�0�� ����0
	}
	//��������
	else if (str[0] == '+') {
		symbol = 1;
		str[0] = '0';
	}
	long long sum = 0;
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] < '0' || str[i] > '9') {
			sum = 0;
			break;
		}
		sum = sum * 10 + str[i] - '0';
	}
	if ((symbol == 1) && sum > 2147483647) {
		return 0;
	}
	if ((symbol ==-1) && sum >= 2147483649) {
		return 0;
	}

	return symbol * sum;
}

#if 0
int main() {
	string str = "-2147483649";
	//for (int i = 0; i < str.size(); ++i) {
	//	str[i] = str[i] - 0;
	//}
	//cout << str << endl;

	cout << StrToInt(str);

	system("pause");
	return 0;
}

class Solution {
public:
	Solution() {
		++n;
		sum += n;
	}
	void request() {
		n = 0;
		sum = 0;
	}
	int Sum_Solution(int n) {
		request();
		Solution a = new Solution[n];
		delete[] a;
		a = nullptr;
		return sum;
	}
private:
	int sum;
	int n;
};
#endif

// n = 5
int Sum_Solution(int n) {
	int ans = n;
	ans && (ans+=Sum_Solution(n - 1));

	return ans;
}

//int main() {
//	cout << Sum_Solution(5) << endl;
//
//	system("pause");
//	return 0;
//}
//
//int LastRemaining_Solution(int n, int m) {
//	if (n == 0 || m == 0) {
//		return -1;
//	}
//	vector<int>vec;
//	for (int i = 0; i < n; ++i) {
//		vec.push_back(i);
//	}
//	int index = -1;
//	auto iter = vec.begin();
//	while (vec.size() > 1) {
//		iter = vec.begin();
//		index = (index + m) % vec.size();
//		vec.erase(iter + index);
//		--index;
//	}
//	return vec[0];
//}
//
//
//int main() {
//	int n = 10;
//	int m = 5;
//	LastRemaining_Solution(n, m);
//
//	system("pause");
//	return 0;
//}
//
//bool IsContinuous(vector<int> numbers) {
//	int size = numbers.size();
//	sort(numbers.begin(), numbers.end());
//	int zero_count = 0;
//	for (int i = 0; i < size; ++i) {
//		if (numbers[i] == 0) {
//			++zero_count;
//		}
//	}
//	int j = 0;
//	for (int i = 0; i < size; ++i) {
//		if (numbers[i] != 0) {
//			j = i;
//			break;
//		}
//	}
//	int start = numbers[j];
//	int end = numbers[size - 1];
//	int nozero_num = end - start + 1;
//	int shi_num = size - zero_count;
//	if ((nozero_num - shi_num) <= zero_count) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
////  0 0  5 6 8 10 11
//int main() {
//	vector<int>vec{0,0,0,1,1};
//	if (IsContinuous(vec)) {
//		cout << "��˳��" << endl;
//	}
//	else {
//		cout << "û��˳��" << endl;
//	}
//	system("pause");
//	return 0;
//}
//
#if 0
int main() {
	string str = "i am a student!";
	string s = str;
	reverse(s.begin(), s.end());
	cout << s << endl;

	system("pause");
	return 0;
}

class TreeNode {
public:
	TreeNode* left;
	TreeNode* right;
};

bool isBalanced = true;
bool IsBalanced_Solution(TreeNode* pRoot) {
	getDepth(pRoot);
	return isBalanced;
}

int getDepth(TreeNode *root) {
	if (root == nullptr) {
		return 0;
	}
	int left = getDepth(root->left);
	int right = getDepth(root->right);
	if (abs(left - right) > 1) {
		isBalanced = false;
	}
	return right > left ? right + 1 : left + 1;
}
#endif

//#if 0
//void test1() {
//	std::string tmp, html;
//	while (getline(std::cin, tmp)) {
//		tmp += '\n';
//		html += tmp;
//	}
//	std::string pattern("http(s)?://([\\w-]+\\.)+[\\w-]+(/[\\w- ./?%&=]*)?");
//	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
//	std::regex r(pattern);
//	for (std::sregex_iterator it(html.begin(), html.end(), r), end;     //end��β���������regex_iterator��regex_iterator��string���͵İ汾
//		it != end; ++it)
//	{
//		std::cout << it->str() << std::endl;
//	}
//}
//
//void test2() {
//	string regex_str("^(\\d{6})((1|2)\\d{3})((0|1)\\d)([0-3]\\d)(\\d{3}(X|\\d))$");
//
//	std::regex pattern(regex_str, std::regex::icase);
//	//������ĸ��Сд
//
//	string id("61251719901212444X");
//	if (std::regex_match(id, pattern) == true) {
//		cout << "ƥ��ɹ�" << endl;
//	}
//
//	// [a-zA-Z0-9_-]+@[a-zA-Z0-9]+\.[a-zA-Z0-9]+  ���������
//	string mail_reg_str("^[a-zA-Z0-9_-]+@[a-zA-Z0-9]+\\.[a-zA-Z0-9]+$");
//	std::regex mail_reg(mail_reg_str, std::regex::icase);
//
//	assert(std::regex_match("chm--1989@163.com", mail_reg) == true);
//}
//
//void IPTest(){
//	//ʶ��һ��IP��ַ������ӡ��������
//	//����exit�˳�����
//	bool isInputEnd = false;
//	//(\d{1,3})\.(\d{1,3})\.(\d{1,3})\.(\d{1,3})
//	//���ĸ��ӱ��ʽ�������е�����Ϊһ���ӱ��ʽ
//	std::regex ip_reg("(\\d{1,3})\\.(\\d{1,3})\\.(\\d{1,3})\\.(\\d{1,3})");
//	std::smatch matchResult;
//	const string exitStr("EXIT");
//	while (!isInputEnd){
//		cout << "\nInput a IP address:";
//		string inputStr;
//		std::getline(std::cin, inputStr);
//		if (inputStr.empty()){
//			continue;
//		}
//
//		string tmpStr(inputStr);
//		std::transform(tmpStr.begin(), tmpStr.end(), tmpStr.begin(), toupper);
//		if (tmpStr == exitStr){
//			cout << "\nSYSTEM EXIT!";
//			isInputEnd = true;
//			continue;
//		}
//		//����ƥ��
//		if (std::regex_match(inputStr, matchResult, ip_reg)){
//			cout << "Match: ";
//			//��ӡ�ӱ��ʽ���
//			for (size_t i = 1; i < matchResult.size(); ++i){
//				cout << matchResult[i] << " ";
//			}
//		}
//		else{
//			cout << "Not Match!";
//		}
//	}
//}
//
//
//int main() {
//	string str = "123143";
//	string regex = "^[0-9]*&";
//	regex_match(str,)
//	//string regex_str = "runoo+b";
//	//std::regex pattern(regex_str, std::regex::icase);
//	//string id = "runoooob";
//	//smatch res;
//	//if (std::regex_match(id,res, pattern)) {
//	//	cout << "ƥ��ɹ�" << endl;
//	//	for (size_t i = 0; i < res.size(); ++i) {
//	//		cout << res[i] << ' ';
//	//	}
//	//	cout << endl;
//	//}
//	//else {
//	//	cout << "û��ƥ����" << endl;
//	//}
//
//	system("pause");
//	return 0;
//}
//
//#endif
