// Source exposure: binary-analysis; no external implementation reused.
// LeafForwarddacb70, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xdacb70 LeafForwarddacb70::Forward
#include "LeafForwarddacb70.h"
extern "C" void* leaf_target(void*);
void* LeafForwarddacb70::Forward() { return leaf_target(this); }
