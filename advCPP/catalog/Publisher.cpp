#include "./include/Publisher.h"

Publisher::Publisher(const std::string& _publisher)
: m_publisher(_publisher)
{

}

const std::string& Publisher::GetPublisher() const
{
	return m_publisher;
}


