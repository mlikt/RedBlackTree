#include "Tree.hpp"

int SPEED = 5;
bool tumbler = OFF;


/*Расскоментруй если отсутсвует программа clear */
// void ClearTerm(){
// 	pid_t pid;
// 	pid = fork();
// 	if (!pid){
// 		std::cout << "\033[2J" << std::flush;
// 		std::cout << "\033c" << std::flush;
// 		exit(0);
// 	}
// 	wait(0);
// }

/*  */
void ClearTerm(){
	pid_t pid;
	pid = fork();
	if (!pid){
		execv("/usr/bin/clear", NULL);
		exit(1);
	}
	wait(0);
}

void UserInterfaceAdd(Tree &tree, bool tumbler){
	int in;
	std::string cmd;
	char ch;

	std::cout << "Построение дерева" << std::endl;
	while (true){
		std::cout << "Введите число: -> ";
		if ( !(std::cin >> std::noskipws >> in >> ch && std::cin.good())) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			if (std::cin.eof()) {
				std::cin.clear();
				ClearTerm();
				break;
			}
			std::cout << "Пожалуйста вводите число." << std::endl;
			std::cout << "Если хотите завершить программу нажмите Ctrl + D " << std::endl;
			std::cout << "Хотите перейти к удалению элементов? (Yes/No) : " ;
			std::getline(std::cin, cmd);
			ClearTerm();
			if (cmd == "Yes" || cmd == "yes" || cmd == "Y" || cmd == "y")
				break;
			std::cout << "Построение дерева" << std::endl;
			tree.PrintGraph(tumbler);
			continue ;
		}
		ClearTerm();
		std::cout << "Построение дерева" << std::endl;
		if (tree.FoundNode(in) == tree.Nil()){
			tree.InsertNode(in);
			tree.PrintGraph(tumbler);
			tree.PrintInfo();
		} else {
			tree.PrintGraph(tumbler);
			tree.PrintInfo();
			std::cout << "Узел " << in << " уже существует" << std::endl;
		}

	}
	std::cout << "Построение завершенно" << std::endl;
}

void UserInterfaceDelete(Tree &tree, bool tumbler){
	int in;
	char ch;
	std::string cmd;

		while (true){
		std::cout << "Удаление узлов дерева" << std::endl;
		tree.PrintGraph(tumbler);
		tree.PrintInfo();

		std::cout << "Введите число: -> ";
		if ( !(std::cin >> std::noskipws >> in >> ch && std::cin.good())) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			if (std::cin.eof()){
				ClearTerm();
				break;
			}
			std::cout << "Пожалуйста вводите число." << std::endl;
			std::cout << "Если хотите завершить программу нажмите Ctrl + D " << std::endl;
			std::cout << "Хотите завершить удаление узлов? (Yes/No) : " ;
			std::getline(std::cin, cmd);
			if (cmd == "Yes" || cmd == "yes" || cmd == "Y" || cmd == "y")
				break;
			ClearTerm();
			continue ;
		}
		ClearTerm();

		if (tree.FoundNode(in) != tree.Nil())
			tree.DeleteNode(in);
		else
			std::cout << "Узел " << in << " отсутствует в дереве." << std::endl;
		if (tree.Root() == tree.Nil()) {
			std::cout << "Дерево пустое" << std::endl;
			break;
		}
	}

}

int main (void ){
	Tree tree;
	char ch = 1;
	std::string cmd;
	std::cout << "Включить отображение листьев(Yes/No)? (По умолчаню: отключено)\n> " << std::flush;
	std::getline(std::cin, cmd);
	if (cmd == "Yes" || cmd == "yes" || cmd == "Y" || cmd == "y")
		tumbler = ON;
	ClearTerm();

	std::cout << "Задать скорость анимации \n> " << std::flush;
    if ( !(std::cin >> std::noskipws >> SPEED >> ch && std::cin.good())) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			if (std::cin.eof()){
				ClearTerm();
				return (0);
			}
	}
	if (ch == 1)
		SPEED = 5;
	
	ClearTerm();
	UserInterfaceAdd(tree, tumbler);
	UserInterfaceDelete(tree, tumbler);
	std::cout << "Введите exit для завершения программы" << std::endl;
	std::cout << "> " << std::flush; 
	std::cin >> std::noskipws >> cmd;
	if (std::cin.eof())
		ClearTerm();
	
	return (0);
}