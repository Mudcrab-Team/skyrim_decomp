// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1414090, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1414090 LeafForward1414090::Forward
#include "LeafForward1414090.h"
extern "C" void* leaf_target(void*);
void* LeafForward1414090::Forward() { return leaf_target(this); }
