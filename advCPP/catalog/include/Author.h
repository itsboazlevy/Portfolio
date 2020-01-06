#ifndef AUTHOR_H
#define AUTHOR_H

#include <string>
#include <cstddef>

class Author
{
public:
	Author(const std::string& _author);
	const std::string& GetAuthor() const;
private:
	const std::string m_author;
};


////////////////////////////////////////////////

bool operator == (const Author& _a, const Author& _b)
{
	return _a.GetAuthor() == _b.GetAuthor(); 
}

class HashAuthor
{
public:
	size_t operator()(const Author& _author) const 
	{
		size_t hash = 5381;
		int temp;
		int i = 0;
		while (( temp = _author.GetAuthor()[i]) != 0)
		{
			hash = ( hash << 5) + hash +temp;
			++i;
		}
		return hash;
	}
};


#endif //AUTHOR_H
