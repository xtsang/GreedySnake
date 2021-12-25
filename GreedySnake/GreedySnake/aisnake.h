#ifndef AISNAKE_H
#define AISNAKE_H

class Snake;
class Food;
class Map;
struct Node {
	int x;
	int	y;
	int	step;
	Node* last;
};

void Machine(Snake&, Snake&, Food&, Map&);

#endif  // AISNAKE_H

