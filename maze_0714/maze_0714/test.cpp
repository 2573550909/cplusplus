#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main(){

	long long n[91] = { 1, 2 };
	for (int i = 2; i <= 90; i++){
		n[i] = n[i - 1] + n[i - 2];
	}

	int d;
	while (std::cin >> d){
		printf("%lld\n", n[d - 1]);
	}

	int n;
	//��������
	while (std::cin >> n){ 
		 //����س�
		std::cin.get();
		std::string name;
		 //���ֱַ���
		for (int i = 0; i < n; i++){
			bool quote = false;
			std::getline(std::cin, name);
			if (name.find(',') != std::string::npos ||
				name.find(' ') != std::string::npos) 
				//�ҵ����Ż��߿ո񣬾�Ҫ��˫����
			{
				quote = true;
			}

			if (quote){
				putchar('\"'); //putcharЧ�ʸ���
			}
			std::cout << name;
			if (quote){
				putchar('\"');
			}

			//����Ѿ������һ���ַ������ǾͲ��س�������Ӷ��źͿո�
			if (i == n - 1) {
				putchar('\n');
			}else{
				putchar(',');
				putchar(' ');
			}
		}
	}
	system("pause");
	return 0;
}