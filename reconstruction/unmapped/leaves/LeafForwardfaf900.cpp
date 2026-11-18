// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfaf900, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfaf900 LeafForwardfaf900::Forward
#include "LeafForwardfaf900.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfaf900::Forward() { return leaf_target(this); }
