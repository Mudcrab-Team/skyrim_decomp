// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardff1800, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xff1800 LeafForwardff1800::Forward
#include "LeafForwardff1800.h"
extern "C" void* leaf_target(void*);
void* LeafForwardff1800::Forward() { return leaf_target(this); }
