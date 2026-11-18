// Source exposure: binary-analysis; no external implementation reused.
// LeafForward156fb50, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x156fb50 LeafForward156fb50::Forward
#include "LeafForward156fb50.h"
extern "C" void* leaf_target(void*);
void* LeafForward156fb50::Forward() { return leaf_target(this); }
