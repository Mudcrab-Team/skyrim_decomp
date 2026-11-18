// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfae500, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfae500 LeafForwardfae500::Forward
#include "LeafForwardfae500.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfae500::Forward() { return leaf_target(this); }
