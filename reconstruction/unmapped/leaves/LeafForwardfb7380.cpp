// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfb7380, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfb7380 LeafForwardfb7380::Forward
#include "LeafForwardfb7380.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfb7380::Forward() { return leaf_target(this); }
