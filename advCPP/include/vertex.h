#ifndef VERTEX_H
#define VERTEX_H
#include "uniqueIdHolder.h"
class Vertex : public UniqueIdHolder
{
public:
	Vertex();
	//~Vertex() = default;
	//virtual size_t getId() const;
private:
	Vertex& operator= (const Vertex&);
	Vertex(const Vertex&);
 	//	size_t id;		
};
#endif // VERTEX_H



