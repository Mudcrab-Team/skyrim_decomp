// Source exposure: binary-analysis; no external implementation reused.
// LeafForward9ecf20, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x9ecf20 LeafForward9ecf20::Forward
#include "LeafForward9ecf20.h"
extern "C" void* leaf_target(void*);
void* LeafForward9ecf20::Forward() { return leaf_target(this); }
