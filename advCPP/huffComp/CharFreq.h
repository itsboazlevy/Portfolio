#ifndef CHARFREQ_H
#define CHARFREQ_H

#include <cstddef>
#include <fstream> 
#include <map>
#include <string>

class CharFreq
{
public:
	CharFreq(const std::string& _fileName);
	//~CharFreq() = default;
	std::map<char, size_t>& Result(); 
private:
	CharFreq(const CharFreq&);
	CharFreq& operator = (const CharFreq&);
	std::map<char, size_t> m_map; 
};

#endif //CHARFREQ_H
