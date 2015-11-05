#include "Relation.h"

ostream& operator<<(ostream& os,const Relation& r)
{
	os << "Relation " << r.getID() << " with " << r.ndrefs.size() << " nodes, " << r.wayrefs.size() << " ways, " << r.relrefs.size() << " relations"<< endl;
	for(const pair<string,string>& t : r.getTags())
		os << "  " << t.first << ": " << t.second << endl;
	return os;
}
