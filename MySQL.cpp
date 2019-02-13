#include "MySQL.h"



MySQL::MySQL()
{
}


MySQL::~MySQL()
{
}

bool MySQL::Connect(const std::string & _szHost, const unsigned short _nPort, const std::string _szDatabase, const std::string & _szUser, const std::string & _szPassWord)
{
	if(NULL == mysql_real_connect(GetMySQL(), _szHost.c_str(),
		_szUser.c_str(), _szPassWord.c_str(),
		_szDatabase.c_str(), _nPort, NULL, NULL))
		return false;
	else return true;
}

bool MySQL::Command(const std::string & _szCommand)
{
	if (0 == mysql_query(GetMySQL(), _szCommand.c_str()))
		return true;
	return false;
}

bool MySQL::IsConnect()
{
	if (0 == mysql_ping(GetMySQL()))
		return true;
	return false;
}

bool MySQL::CreateDatabase(const std::string & _szDB)
{
	std::string szCmd = "CREATE DATABASE " + _szDB;
	return Command(szCmd);
}

bool MySQL::SelectDatabase(const std::string & _szDB)
{
	if (0 == mysql_select_db(GetMySQL(), _szDB.c_str()))
		return true;
	return false;
}

bool MySQL::DeleteDatabase(const std::string & _szDB)
{
	std::string szCmd = "DROP DATABASE " + _szDB;
	return Command(szCmd);
}

bool MySQL::FreeResult()
{
	MYSQL_RES* pRes = mysql_store_result(GetMySQL());
	mysql_free_result(pRes);
	return true;
}

std::string MySQL::GetErrorMessage()
{
	return std::string(mysql_error(GetMySQL()));
}

unsigned int MySQL::GetErrorID()
{
	return mysql_errno(GetMySQL());
}

long NameMySQL::GetResult(void ** pBuf)
{
	if (pBuf == NULL)return -1;
	MYSQL_RES *pResult = mysql_store_result(GetMySQL());
	MYSQL_ROW ResultRow;
	unsigned int unResultCols = mysql_num_fields(pResult);
	unsigned int unResultRows = mysql_num_rows(pResult);
	std::string *pReturn = new std::string[unResultRows];
	short nReturnIndex = 0;
	while (ResultRow = mysql_fetch_row(pResult))
	{
		for (unsigned int unResultCol = 0; unResultCol < unResultCols; unResultCol++)
		{
			pReturn[nReturnIndex] += ResultRow[unResultCol];
		}
		nReturnIndex++;
	}
	FreeResult();
	*pBuf = pReturn;
	return unResultRows;
}
