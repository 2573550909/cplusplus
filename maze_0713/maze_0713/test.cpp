/*�����ж������ݣ�ÿ�����������С�
��һ�г����б�����֮����һ�����Ÿ�����
��������а����ո�򶺺ţ�������������˫������ܳ��Ȳ�����512���ַ���
�ڶ���ֻ����һ���������Ǵ����ҵ��û������֣�����Ҫ��ȫƥ�䣩��
���Ȳ�����16���ַ���
�������������ڶ��е����ֳ������ռ����б��У��������Ignore����
��ʾ����ʼ�����Ҫ�����������Important!����
��ʾ����ʼ���Ҫ�����ȴ���
ʾ��1 :����
Joe, Kewell, Leon
Joe
"Letendre, Bruce", Joe, "Quan, William"
William
���
Ignore
Important!*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
	std::string line;
	// ��һ�ε�����ץ�� line ��
	while (getline(cin, line)) {
		//names �������е�����
		vector<string> names; 
		size_t pos = 0;
		// λ��������ڵ����˳��ȣ���ô֤�������ˣ�˫���ŵ��������������
		while (pos < line.length()) {
			// �ҵ�˫����Ҫ����˫�����ڲ�
			if (line[pos] == '\"') {
				size_t end = line.find("\"", pos + 1);
				names.push_back(line.substr(pos + 1, end - pos - 1));
				// ��ȡ�����ŵ� names ��
				pos = end + 2;
				// ���������˫���źͶ���
			}else{
				size_t end = line.find(",", pos + 1);
				// �Ҳ�������֤���������һ���ַ����ˣ�
				//ֱ�Ӵ�������ַ���������
				if (end == -1) {
					names.push_back(line.substr(pos, line.size() - pos));
					break;
				}
				names.push_back(line.substr(pos, end - pos));
				pos = end + 1; // ��������Ķ���
			}
		}

		std::getline(cin, line);
		if (names.end() == find(names.begin(), names.end(), line))
			//std::find �������������������м���ң����һ��������Ҫ�ҵ�ֵ��
			// �ҵ��˷��ض�Ӧ���������Ҳ����ͷ�������ĩβ��λ�á�
			//�������� end() ��
		{
			printf("Important!\n"); // û�ҵ�
		}else{
			printf("Ignore\n"); // �ҵ���
		}
	}
	return 0;
}

//#include <iostream>
//#include <stdlib.h>
//using namespace std;
//
//int main() {
//	int n;
//	//��������н��ĸ����� 1- �����˶��н��ĸ���
//	while (cin >> n) {
//		int sum = 1;
//		for (int i = 0; i < n; ++i) {
//			sum = sum * 1 / n;
//		}
//		int p = 1 - sum;
//		printf("%.2f%%\n", p);
//	}
//
//	system("pause");
//	return 0;
//}
//
//1. ���ȣ�������Ա����һ��д���Լ����ֵ���������齱���У�
//2. ����������������ϣ�ÿ�˴�����ȡһ��������
//3. ����鵽��������д�ľ����Լ������֣���ô����ϲ�㣬�н��ˣ���
//���ڸ�����μ�������������������ж��ٸ��ʻ�������˻񽱣�
//������������������������ݣ�ÿ�����ݰ���һ��������n��2��n��20����
//�����������Ӧÿһ�����ݣ��ԡ�xx.xx%���ĸ�ʽ����������˻񽱵ĸ��ʡ�
	//����:2
	//���:50.00%