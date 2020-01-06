#ifndef YEAR_H
#define YEAR_H

#include <string>

class Year
{
public:
	Year(const std::string& _year);
	const std::string& GetYear() const;
private:
	const std::string m_year;
};

#endif //YEAR_H
