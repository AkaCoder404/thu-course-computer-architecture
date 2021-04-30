#pragma once
#include "cache.h"
#include <iostream>

using namespace std;

class Solver {
public:
	// TODO : implement getAns, 获取目标信息
	int getAns(BaseCache* cache, int addresses, int lines);
};
