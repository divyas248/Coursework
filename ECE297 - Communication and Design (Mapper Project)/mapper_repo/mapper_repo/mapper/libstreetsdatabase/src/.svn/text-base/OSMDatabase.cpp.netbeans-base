#include "OSMDatabase.h"
#include <iostream>
#include <iomanip>

using namespace std;

OSMDatabase::OSMDatabase(const vector<Node>& nodes_,const vector<Way>& ways_,const vector<Relation>& relations_) :
	nodes(nodes_),ways(ways_),relations(relations_)
{
	// generate mapping from node ID to node vector index
	for(const Node& n : nodes)
		nodes_map.insert(make_pair(n.getID(),0));

	unsigned i=0;
	for(pair<const unsigned long long,unsigned>& p : nodes_map)
		p.second = i++;

	// generate mapping from way ID to way vector index
	i=0;
	for(const Way& w : ways)
		ways_map.insert(make_pair(w.getID(),0));

	for(pair<const unsigned long long,unsigned>& p : ways_map)
		p.second = i++;

	map<unsigned long long,unsigned> missingNodes;
	map<unsigned long long,unsigned> referencedNodes;
	unsigned missing=0,valid=0;


	// check that all way mappings have matching node refs
	for(const Way& w : ways)
	{
		unsigned i=0;
		for(unsigned long long n : w.getRefs())
		{
			if (nodes_map.find(n) == nodes_map.end())
			{
				//cout << "ERROR: Node-ref " << n << " not found in nodes map (way element " << i << '/' << N << ')' << endl;
				missingNodes[n]++;
				missing++;
			}
			else
			{
				referencedNodes[n]++;
				valid++;
			}
			++i;
		}
	}

	cout << "There are " << missingNodes.size() << " invalid node references, and " << referencedNodes.size() << " distinct referenced nodes" << endl;
	cout << "  Total " << missing << " missing refs, " << valid << " valid" << endl;

	ways_mapped=mapWays(nodes_map);

	map<unsigned,unsigned> node_ref_count_hist;

	for(const pair<unsigned long long,unsigned>& n : referencedNodes)
		node_ref_count_hist[n.second]++;

	cout << "Reference count histogram" << endl;

	for(const pair<unsigned,unsigned> p : node_ref_count_hist)
		cout << "  " << p.first << "references: " << p.second << "instances" <<endl;
}

vector<Way> OSMDatabase::mapWays(const map<unsigned long long,unsigned>& nodes_map_) const
{
	vector<Way> wm=ways;

	// Do way remapping using simple method
	for(Way& w : wm)
	{
		vector<unsigned long long>::iterator i,o;
		map<unsigned long long,unsigned>::const_iterator nmap;
		for(i=o=w.ndrefs.begin(); i != w.ndrefs.end(); ++i)
		{
			nmap = nodes_map_.find(*i);		// find the node mapping
			if(nmap != nodes_map_.end())		// if has a valid node mapping, then copy it else drop from array
				*(o++) = nmap->second;
		}
		w.ndrefs.resize(o-w.ndrefs.begin());				// resize vector
	}

	return wm;
}

/** Gets a count of references to each node (by node ID) in the ways
 * @return pair<unsigned,map<unsigned long long,unsigned>> Returns a pair where p.first=# of total references, p.second=map {Node ID -> ref count}
 */

pair<unsigned,map<unsigned long long,unsigned>> OSMDatabase::getNodeRefCounts() const
{
	unsigned total_refs=0;
	map<unsigned long long,unsigned> node_ref_counts;

	for(const Way& w : ways)
		for(unsigned long long n : w.ndrefs)
		{
			node_ref_counts[n]++;
			total_refs++;
		}
	return make_pair(total_refs,node_ref_counts);
}

/**
 * Gets a histogram of node reference counts.
 *
 * @return Map giving, for each node ID, the number of times it is referenced in a way
 */

map<unsigned,unsigned> OSMDatabase::getNodeRefHist() const
{
	map<unsigned,unsigned> node_ref_count_hist;

	unsigned total_refs;
	map<unsigned long long,unsigned> node_ref_counts;

	tie(total_refs,node_ref_counts) = getNodeRefCounts();

	// count counts
	for(const pair<unsigned long long,unsigned>& p : node_ref_counts)
		node_ref_count_hist[p.second]++;

	cout << "Reference count histogram" << endl;

	// number of nodes receiving no reference at all
	cout << "  0 references: " << nodes.size()-node_ref_counts.size() << endl;

	// node reference histogram
	unsigned sum_refs=0;
	for(const pair<unsigned,unsigned> p : node_ref_count_hist)
	{
		sum_refs += p.second*p.first;
		cout << "  " << setw(4) << p.first << " references: " << setw(8) << p.second << " instances" << endl;
	}

	cout << " -- Total references: " << sum_refs << " (expecting " << total_refs << ')' << endl;

	return node_ref_count_hist;
}
