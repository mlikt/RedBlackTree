#include "Tree.hpp"

void Tree::FixDelete(Node *node) {

    while (node != root && node->colour == Black) {
        ClearTerm();
        std::cout << "Удаление узлов дерева" << std::endl;
        this->PrintGraph(tumbler);
        this->PrintInfo();
        if (IamLeftOrRight(node) == LEFT) {
            Node *w = node->Parent->Right;
            if (w->colour == Red) {
                w->colour = Black;
                node->Parent->colour = Red;
                RotateLeft (node->Parent);
                w = node->Parent->Right;
            }
            if (w->Left->colour == Black && w->Right->colour == Black) {
                w->colour = Red;
                node = node->Parent;
            } else {
                if (w->Right->colour == Black) {
                    w->Left->colour = Black;
                    w->colour = Red;
                    RotateRight (w);
                    w = node->Parent->Right;
                }
                w->colour = node->Parent->colour;
                node->Parent->colour = Black;
                w->Right->colour = Black;
                RotateLeft (node->Parent);
                node = root;
            }
        } else {
            Node *w = node->Parent->Left;
            if (w->colour == Red) {
                w->colour = Black;
                node->Parent->colour = Red;
                RotateRight (node->Parent);
                w = node->Parent->Left;
            }
            if (w->Right->colour == Black && w->Left->colour == Black) {
                w->colour = Red;
                node = node->Parent;
            } else {
                if (w->Left->colour == Black) {
                    w->Right->colour = Black;
                    w->colour = Red;
                    RotateLeft (w);
                    w = node->Parent->Left;
                }
                w->colour = node->Parent->colour;
                node->Parent->colour = Black;
                w->Left->colour = Black;
                RotateRight (node->Parent);
                node = root;
            }
        }
    usleep(SPEED * 100000);
    }

    node->colour = Black;
    this->root = FoundRoot(node);

}

void Tree::DeleteNode(T key) {
    
    Node *node = FoundNode(key);
    Node *child, *near;

    if (!node || node == NIL) return;


    if (node->Left == NIL || node->Right == NIL)
        near = node;
    else 
        near = Min(node->Right);
    
    if (near->Left != NIL)
        child = near->Left;
    else
        child = near->Right;

    child->Parent = near->Parent;
    if (Parent(near))
        if (IamLeftOrRight(near) == LEFT)
            near->Parent->Left = child;
        else
            near->Parent->Right = child;
    else
        this->root = child;

    if (near != node) node->value = near->value; //А если константа? Конст каст?


    if (near->colour == Black)
        FixDelete(child);
    
    ClearTerm();
    std::cout << "Удаление узлов дерева" << std::endl;
    this->PrintGraph(tumbler);
    this->PrintInfo();
    usleep(SPEED * 100000);

    delete near;
}