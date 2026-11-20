// Source exposure: binary-analysis; no external implementation reused.
// LeafForward83ec60, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x83ec60 LeafForward83ec60::Forward
#include "LeafForward83ec60.h"
extern "C" void* leaf_target(void*);
void* LeafForward83ec60::Forward() { return leaf_target(this); }
