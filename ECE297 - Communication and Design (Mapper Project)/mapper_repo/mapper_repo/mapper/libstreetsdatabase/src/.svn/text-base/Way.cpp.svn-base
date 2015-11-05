#include "Way.h"

using namespace std;

ostream& operator<<(ostream& os,const Way& w)
{
	os << "Way " << w.getID() << endl;
	for(const pair<string,string>& t : w.getTags())
		os << "  " << t.first << ": " << t.second << endl;
	return os;
}
