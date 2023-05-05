#include "SLLNode.h"

SLLNode::SLLNode (int i, SLLNode* n) {
        value = i;
        next = n;
}
SLLNode::SLLNode () {
        value = 0;
        next = NULL;
}