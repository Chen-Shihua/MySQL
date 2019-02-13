#ifndef MYSQL_H
#define MYSQL_H

#include "SQL.h"
#include <string>
#include <list>

class MySQL :
	public SQL
{
public:
	MySQL();
	~MySQL();
	virtual bool Connect(const std::string& _szHost, const unsigned short _nPort, const std::string _szDatabase, const std::string& _szUser, const std::string& _szPassWord);
	virtual bool Command(const std::string& _szCommand);
	virtual bool IsConnect();
	virtual bool CreateDatabase(const std::string& _szDB);
	virtual bool SelectDatabase(const std::string& _szDB);
	virtual bool DeleteDatabase(const std::string& _szDB);
	virtual bool FreeResult();
	virtual long GetResult(void **pBuf) = 0;;
	std::string GetErrorMessage();
	unsigned int GetErrorID();
};

class NameMySQL :
	public MySQL
{
public:
	virtual long GetResult(void **pBuf);
};
#endif // MYSQL_H