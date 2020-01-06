#include "./include/Year.h"

Year::Year(const std::string& _year)
: m_year(_year)
{

}

const std::string& Year::GetYear() const
{
	return m_year;
}
