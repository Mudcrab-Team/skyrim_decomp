// Source exposure: binary-analysis; no external implementation reused.
// LeafForward83e050, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x83e050 LeafForward83e050::Forward
#include "LeafForward83e050.h"
extern "C" void* leaf_target(void*);
void* LeafForward83e050::Forward() { return leaf_target(this); }
