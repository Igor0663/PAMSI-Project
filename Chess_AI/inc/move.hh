#ifndef MOVE_HH
#define MOVE_HH
#define INF 8

struct move{
	int h_move;
	int v_move;
	unsigned int max_rep;
	bool only_first;
	int type;// 0 - capture or move 1 - only capture 2 - only move 
	move(int h, int v, unsigned int rep = 1, bool of = 0, int t = 0 ): h_move(h), v_move(v), max_rep(rep), only_first(of), type(t) {}
};

#endif
