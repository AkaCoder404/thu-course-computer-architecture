#pragma once
#include <iostream>
#include <cstdlib>

using namespace std;

class BaseCache {
	/* Contains 32 Cache Lines, organized in a direct mapping manner 
	 (Address% 32 is the mapped Cache Line). */

	// undefined address
	int u;

	int line;
	int tag[32];				// physical address of storage
	bool valid[32];			// valid or not
	int time[32];				// timing

	// memory address count
	int count;

	void state_rand();

public:
	BaseCache(int _u, int _line);

	int getCount();

	// clear the address x from the cache, if it hits, the delay is high, otherwise the delay is low.
	int flush(int x);
	// read and write address x, if it hits, the delay is low, otherwise the delay is high.
	int access(int x);
	
	
	// for flush and access of address u, no parameters are required, and the return value is the same as general flush and access
	int accessu();

	int flushu();	

	// the entire cache situation, if there is valid data in the cache, the delay is high, otherwise the delay is low
	// high delay return 1, low delay return 0
	int flushAny();
};
