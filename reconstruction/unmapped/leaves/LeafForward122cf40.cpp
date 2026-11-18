// Source exposure: binary-analysis; no external implementation reused.
// LeafForward122cf40, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x122cf40 LeafForward122cf40::Forward
#include "LeafForward122cf40.h"
extern "C" void* leaf_target(void*);
void* LeafForward122cf40::Forward() { return leaf_target(this); }
