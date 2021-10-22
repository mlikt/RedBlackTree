#ifndef __NODE_H__
	#define __NODE_H__

#define BLACK  "\033[22;2m"
#define YELLOW    "\033[22;33m"
#define RED  "\033[22;31m"
#define GREEN "\e[0;32m"
#define BLUE  "\033[40;34m"
#define RESETCOLOR "\033[0m"


// Политра
enum Colour {Red, Black};
typedef int T;

typedef struct Node_
{
	T value;
	Colour colour;

	struct Node_ * Left;
	struct Node_ * Parent;
	struct Node_ * Right;

} Node;

// Конечный элемент, лист

#endif