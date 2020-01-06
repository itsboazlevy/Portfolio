#ifndef CAT
#define CAT

class Cat 
{
public:
	Cat();
	virtual ~Cat();
	virtual void eat();
	virtual void play();
};

extern "C" Cat* creator();

#endif //CAT
