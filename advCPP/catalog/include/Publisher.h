#ifndef PUBLISHER_H
#define PUBLISHER_H

#include <string>

class Publisher
{
public:
	Publisher(const std::string& _publisher);
	const std::string& GetPublisher() const;
private:
	const std::string m_publisher;
};

////////////////////////////////////////////////

bool operator == (const Publisher& _a, const Publisher& _b)
{
	return _a.GetPublisher() == _b.GetPublisher(); 
}

class HashPublisher
{
public:
	size_t operator()(const Publisher& _publisher) const 
	{
		size_t hash = 5381;
		int temp;
		int i = 0;
		while (( temp = _publisher.GetPublisher()[i]) != 0)
		{
			hash = ( hash << 5) + hash +temp;
			++i;
		}
		return hash;
	}
};

#endif //PUBLISHER_H
