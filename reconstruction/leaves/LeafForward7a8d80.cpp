// Source exposure: binary-analysis; no external implementation reused.
// LeafForward7a8d80, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x7a8d80 LeafForward7a8d80::Forward
#include "LeafForward7a8d80.h"
extern "C" void* leaf_target(void*);
void* LeafForward7a8d80::Forward() { return leaf_target(this); }
