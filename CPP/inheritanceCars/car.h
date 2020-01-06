/*	Description: C++ Inheritance exercise
	Author: Boaz L
	Created: 11.4.19
	Last Update: 14.4.19
*/
#ifndef __CAR_H__
#define __CAR_H__
#include <stdlib.h>
class car_t
{
	public:
		car_t();										/* default CTOR */
		car_t(const char* _capacity);					/* cap based CTOR */
		car_t(const car_t& _carRef);					/* copy CTOR */	
		inline char* getName () const;
		inline bool getGear () const;
		bool typeCompare (const car_t& _carRef);		/* true if type is the same */	
		car_t& operator = (const car_t& _carRef);		/* assignment */
		bool operator < (const car_t& _carRef) const;	/* comparison by capacity - overload to compare diffrent car types */	
	protected: 
		void setGear (bool _gear);
		void setName (char _name);
		~car_t();										/* DTOR - under protected to block car creation by user*/
	private:
		const char* capacity;
		static size_t id;								/* manages id : first id given is 0, incremented by 1 for each CTOR */
		size_t objID;									/* actual id of object */
		bool gear;										/* gear will be set by derived objects, 0/1 for auto/manual */
		char name;										/* name will be set by derived objects, B/P for bus/private */
		char* createFrom (const char* _str);			

};

class private_t:car_t
{
	public:
		private_t();									
		private_t(const char* _capacity, bool _gear, size_t _speed);					
		private_t(const private_t& _privRef);					
		~private_t();
		inline void accelerate () ;						/* increase speed by 10 */
		inline void decelerate () ;						/* decrease speed by 10 */
		inline size_t getSpeed () const;
	private:
		size_t speed;
};

class bus_t:car_t	
{
	public:
		bus_t();									
		bus_t(const char* _capacity, bool _gear, size_t _seatNum, size_t _lineNum);					
		bus_t(const bus_t& _busRef);					
		~bus_t();
		inline size_t getSeatNum () const;
		inline size_t getLineNum () const;
	private:
		size_t seatNum;
		size_t lineNum;
};

#endif /* __CAR_H__ */
