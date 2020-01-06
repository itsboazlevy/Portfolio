#ifndef ISBN_H
#define ISBN_H

#include <string>

class ISBN
{
public:
	ISBN(const std::string& _isbn);
	const std::string& GetISBN() const;
private:
	const std::string m_isbn;
};

////////////////////////////////////////////////

bool operator == (const ISBN& _a, const ISBN& _b)
{
	return _a.GetISBN() == _b.GetISBN(); 
}

class HashISBN
{
public:
	size_t operator()(const ISBN& _isbn) const 
	{
		size_t hash = 5381;
		int temp;
		int i = 0;
		while (( temp = _isbn.GetISBN()[i]) != 0)
		{
			hash = ( hash << 5) + hash +temp;
			++i;
		}
		return hash;
	}
};

#endif //ISBN_H
