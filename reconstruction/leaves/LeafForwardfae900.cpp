// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfae900, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfae900 LeafForwardfae900::Forward
#include "LeafForwardfae900.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfae900::Forward() { return leaf_target(this); }
