#include "list_functions.h"

ListItr ListItr_FindFirst(ListItr _begin, ListItr _end, PredicateFunction _predicate, void* _context)
{
	void* temp;
	while (_begin != _end)
	{
		temp = ListItr_Get(_begin);
		if ( _predicate(temp, _context) )
		{
			return _begin;
		}
		_begin =  ListItr_Next(_begin);
	}
	return _begin;
}


size_t ListItr_CountIf(ListItr _begin, ListItr _end, PredicateFunction _predicate, void* _context)
{
	void* temp;
	size_t count = 0;
	while (_begin != _end)
	{
		temp = ListItr_Get(_begin);
		if ( _predicate(temp, _context) )
		{
			count++;
		}
		_begin =  ListItr_Next(_begin);
	}
	return count;
}

ListItr ListItr_ForEach(ListItr _begin, ListItr _end, ListActionFunction _action, void* _context)
{
	void* temp;
	while (_begin != _end)
	{
		temp = ListItr_Get(_begin);
		if (_action(temp, _context) == 0)
		{
			break;
		}
		_begin = ListItr_Next(_begin);
	}
	return _begin;
}
/*
void ListItr_Sort(ListItr _begin, ListItr _end, LessFunction _less)
{
	void* a;
	void* b;
	while (ListItr_Next(_begin) != _end)
	{
		a = ListItr_Get(_begin);
		b = ListItr_Get(ListItr_Next(_begin));
		if (_less(a,b) == 0)
		{
			
		}
		_begin = ListItr_Next(_begin);
	}
	return _begin;
}


*/






