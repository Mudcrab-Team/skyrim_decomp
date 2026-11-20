// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1003970, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1003970 LeafForward1003970::Forward
#include "LeafForward1003970.h"
extern "C" void* leaf_target(void*);
void* LeafForward1003970::Forward() { return leaf_target(this); }
