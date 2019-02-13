#ifndef SQL_H
#define SQL_H

#include <mysql.h>
#include <string>
class SQL
{
public:
	SQL();
	virtual ~SQL();

protected:
	inline MYSQL* GetMySQL();

private:
	MYSQL m_sql;
};

#endif // SQL_H