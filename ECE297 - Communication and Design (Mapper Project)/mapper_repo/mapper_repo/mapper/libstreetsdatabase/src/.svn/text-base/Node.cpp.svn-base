#include "Node.h"

std::ostream& operator<<(std::ostream& os,const Node& n)
{
	os << "Node " << n.getID() << " at (" << n.lat << ',' << n.lon << ")" << std::endl;
	for(const std::pair<std::string,std::string>& t : n.getTags())
		os << "  " << t.first << ": " << t.second << std::endl;
	return os;
}
