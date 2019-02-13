#include "MySQL.h"
#include <iostream>

int main()
{
	NameMySQL sql;
	std::cout << "数据库连接状态:" << sql.IsConnect() << std::endl;
	if (sql.Connect("127.0.0.1", 3306, "mysql", "root", "123456"))
		std::cout << "数据库连接成功" << std::endl;
	else std::cout << "数据库连接失败" << std::endl;
	std::cout << "数据库连接状态:" << sql.IsConnect() << std::endl;
	if (sql.CreateDatabase("my_test_database"))
		std::cout << "创建数据库成功" << std::endl;
	else std::cout << "创建数据库失败" << std::endl;
	if (sql.SelectDatabase("my_test_database"))
		std::cout << "选择数据库成功" << std::endl;
	else std::cout << "选择数据库失败" << std::endl;

	//std::string szCreateTable = "CREATE TABLE name(Name varchar(128))";
	//if (sql.Command(szCreateTable))
	//	std::cout << "创建表成功" << std::endl;
	//else std::cout << "创建表失败:" << sql.GetErrorMessage() << std::endl;

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