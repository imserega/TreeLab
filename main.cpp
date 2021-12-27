
//Includes
#include "iterator.h"
#include "queue.h"
#include "stack.h"
#include "Tree.h"

//Driver code
int main() {

    Tree a;
    cout << "Filling the Tree with elements\n";
                    //           Tree 
    a.insert(55);   //            55
    a.insert(45);   //         45    56
    a.insert(56);   //       35        60
    a.insert(35);   //     23            62
    a.insert(60);   //  20    24      61      68
    a.insert(23);   // 14                  66
    a.insert(62);
    a.insert(61);
    a.insert(20);   
    a.insert(24);   
    a.insert(68);
    a.insert(66);
    a.insert(14);   

    cout << "Tree\n              55\n           45   56\n         35       60\n      23             62\n  20    24        61     68\n 14                    66\n";

    cout << "Depth Tree traversal >>> ";

    Iterator* Tree_iterator_stack = a.create_dft_iterator();
    while (Tree_iterator_stack->has_next()) {
        cout << Tree_iterator_stack->next() << ' ';
    }
    cout << endl << endl;

    cout << "Breadth Tree traversal >>> ";

    Iterator* Tree_iterator_queue = a.create_bft_iterator();
    while (Tree_iterator_queue->has_next()) {
        cout << Tree_iterator_queue->next() << ' ';
    }
    cout << endl;

    return 0;
}
