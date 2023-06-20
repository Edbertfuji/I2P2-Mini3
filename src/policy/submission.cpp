#include <cstdlib>
#include "../state/state.hpp"
#include "./submission.hpp"


int Submission::Minmax(State* state, int depth, bool Max_play) {
		int minimum = 100000000;
        if (!Max_play) {
			State* mstate = new State(state->board, !state->player);

        if (depth == 0){
		return mstate->evaluate();
        }

		for (auto& iter : state->legal_actions) {
			State* st = state->next_state(iter);
			minimum = std::min(minimum, Minmax(st, depth - 1, true));
		}
		return minimum;
		

	}
	else {
		int maximum = -100000000;
        if (depth == 0){
			return state->evaluate();
        }

		for (auto& iter : state->legal_actions) {
			State* st = state->next_state(iter);
			maximum = std::max(maximum, Minmax(st, depth - 1, false));
		}
		return maximum;
	}
}
