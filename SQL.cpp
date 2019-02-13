#include "SQL.h"



SQL::SQL()
{
	mysql_init(GetMySQL());
}


SQL::~SQL()
{
	mysql_close(GetMySQL());
}

inline MYSQL * SQL::GetMySQL()
{
	return &m_sql;
}
