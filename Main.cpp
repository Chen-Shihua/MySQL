#include "MySQL.h"
#include <iostream>

int main()
{
	NameMySQL sql;
	std::cout << "���ݿ�����״̬:" << sql.IsConnect() << std::endl;
	if (sql.Connect("127.0.0.1", 3306, "mysql", "root", "123456"))
		std::cout << "���ݿ����ӳɹ�" << std::endl;
	else std::cout << "���ݿ�����ʧ��" << std::endl;
	std::cout << "���ݿ�����״̬:" << sql.IsConnect() << std::endl;
	if (sql.CreateDatabase("my_test_database"))
		std::cout << "�������ݿ�ɹ�" << std::endl;
	else std::cout << "�������ݿ�ʧ��" << std::endl;
	if (sql.SelectDatabase("my_test_database"))
		std::cout << "ѡ�����ݿ�ɹ�" << std::endl;
	else std::cout << "ѡ�����ݿ�ʧ��" << std::endl;

	//std::string szCreateTable = "CREATE TABLE name(Name varchar(128))";
	//if (sql.Command(szCreateTable))
	//	std::cout << "������ɹ�" << std::endl;
	//else std::cout << "������ʧ��:" << sql.GetErrorMessage() << std::endl;

	sql.Command("SELECT * FROM name");
	std::string* pBuf = NULL;
	long count = sql.GetResult((void**)&pBuf);
	for (int index = 0; index < count; index++)
		std::cout << pBuf[index] << std::endl;
	delete[] pBuf;
	pBuf = NULL;

	system("pause");
	return 0;
}