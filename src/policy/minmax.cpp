#include <cstdlib>

#include "../state/state.hpp"
#include "./minmax.h"


/**
 * @brief Randomly get a legal action
 *
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move
 */
int MinMax::Minmax(State* state, int depth, bool maxPlayer) {
	if (depth == 0) 
		return state->evaluate();
	else if (maxPlayer) {
		int maximum = -1000000000;
		for (auto& cur : state->legal_actions) {
			State* st = state->next_state(cur);
			maximum = std::max(maximum, Minmax(st, depth - 1, false));
		}
		return maximum;
	}
	else {
		int minimum = 1000000000;
		for (auto& cur : state->legal_actions) {
			State* st = state->next_state(cur);
			minimum = std::min(minimum, Minmax(st, depth - 1, true));
		}
		return minimum;
	}
}