#include "stringFuncs.h"
#include <stdio.h>
int StrLen(const char* _str)
{
	int count = 0;
	if (_str == NULL)
	{
		return 0;
	}
	while (_str[count] != '\0')
	{
		count++;	
	}
	return count;
}

int StrLenRec(const char* _str)
{
	if (_str == NULL)
	{
		return 0;
	}
	if (*_str == '\0')
	{
		return 0;
	}
	return StrLenRec(_str+1) +1;
}

int StrCompare (const char* _s1, const char* _s2)
{
	int count = 0;
	if (_s1 == NULL || _s2 == NULL)
	{
		return 0;
	}
	if (StrLen(_s1) != StrLen(_s2))
	{
		return 0;
	}
	while (_s1[count] != '\0')
	{
		if (_s1[count] != _s2[count])
		{
			return 0;
		}
		count++;
	}
	return 1;
}

int StrCompareRec (const char* _s1, const char* _s2)
{
	int temp = 1;
	if (_s1 == NULL || _s2 == NULL)
	{
		return 0;
	}
	if (*_s1 != *_s2)
	{
		return 0;
	}
	if (*_s1 == *_s2 && *_s1 == '\0')
	{
		return 1;
	}
	temp *= StrCompareRec(_s1+1,_s2+1);
	return temp;
}

char* StrCopy (char* _destination, const char* _source)
{
	int count, size, size2;
	size = StrLen(_source);
	size2 = StrLen(_destination);
	if (_destination == NULL || _source == NULL)
	{
		return NULL;
	}
	for (count = 0; count < size+1 && count < size2; count++)
	{
		_destination[count] = _source[count];
	}
	return _destination;
}

char* StrCopyRec (char* _destination, const char* _source)
{
	if (_destination == NULL || _source == NULL)
	{
		return NULL;
	}
	if (*_destination == '\0' || *_source == '\0')
	{
		return _destination;
	}
	*_destination = *_source;
	StrCopyRec (_destination+1,_source+1);
	return _destination;
}

char* StrNCopy (char* _destination, const char* _source, size_t _num)
{
	int count, size, size2;
	size = StrLen(_source);
	size2 = StrLen(_destination);
	if (_destination == NULL || _source == NULL)
	{
		return NULL;
	}
	for (count = 0; count < size && count < size2 && count <_num; count++)
	{
		_destination[count] = _source[count];
	}
	_destination[count] = '\0';
	return _destination;
}

char* StrNCopyRec (char* _destination, const char* _source, size_t _num)
{
	if (_destination == NULL || _source == NULL)
	{
		return NULL;
	}
	if (*_destination == '\0' || *_source == '\0' || _num <= 0)
	{
		*_destination = '\0';
		return _destination;
	}
	*_destination = *_source;
	StrNCopyRec (_destination+1,_source+1, _num-1);
	return _destination;
}

char* StrConcat (char* _destination, const char* _source)
{
	int count, count2, size, size2;
	size = StrLen(_source);
	size2 = StrLen(_destination);
	if (_destination == NULL || _source == NULL)
	{
		return NULL;
	}
	for (count = size2, count2 = 0; count2 < size; count2++, count++)
	{
		_destination[count] = _source[count2];
	}
	return _destination;
}

char* StrSubString (const char* _str, const char* _search)
{
	int count, count2, size, size2, flag;
	size = StrLen(_str);
	size2 = StrLen(_search);
	for (count = 0; count < size; count++)
	{
		if(_str[count] == _search[0])
		{
			flag = 0;
			for (count2 = 1; count2 < size2; count2++)
			{
				if(_str[count+count2] != _search[0+count2])
				{
					flag = 1;
					break;
				}
			}
			if (flag == 0)
			{
				return _str+count;
			}
		}
	}
	return _str+count;
}

