#pragma once
#include "../state/state.hpp"



class MinMax {
public:
	static int Minmax(State* state, int depth, bool Max_player);
};
