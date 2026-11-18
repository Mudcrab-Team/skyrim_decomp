// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfbc090, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfbc090 LeafForwardfbc090::Forward
#include "LeafForwardfbc090.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfbc090::Forward() { return leaf_target(this); }
