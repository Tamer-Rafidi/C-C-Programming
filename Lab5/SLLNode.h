#ifndef SRC_SLLNODE_H_
#define SRC_SLLNODE_H_

#include <stdlib.h>
using namespace std;
class SLLNode {


public:
    int value;
    SLLNode* next;


    SLLNode(int i, SLLNode* n);
    SLLNode();

};



#endif /* SRC_SLLNODE_H_ */