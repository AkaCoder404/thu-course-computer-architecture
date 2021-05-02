#include "solver.h"
#include "cache.h"
#include <iostream>

int Solver::getAns(BaseCache* cache, int addresses, int lines) {
	// TODO 
	// clear cache 	
	cache->flushAny();
	// conform which line u is in
	cache->accessu();
	
	int cache_line_num = 0;
	int delay_short = 0;
	int delay_long = 1;
	// search the lines
	for(int i = 0; i < lines; i++) {
		// if access delay time is short, then it means its a hit
		if(cache->access(i) == delay_short) return i;
		// if it is not hit, the address i may replace the address u or the address i and the address u exist at the same time, 
		// then visit address i and then visit the u, if the delay time is long, it indicates that u has been replaced, then u is stored in the ith line.
		// confirm line where u is, if valid data, return cache line_num
		// correctly map known address u to ith line
 		else if(cache->accessu() == delay_long) { 
			cache_line_num = i;
			break;
		}
	}
	
	cache->accessu();
	// search among all addresses that are in the cache line_num
	// use the line number 32 as the step size to clear all the addresses i.
	// only when u == i can it hit and be cleared successfully, thus successfuly attacking the unknown address
	for(int i = cache_line_num; i < addresses; i += 32) 
		if(cache->flush(i) == delay_long) return i;		
}
