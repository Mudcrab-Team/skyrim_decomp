// Source exposure: binary-analysis; no external implementation reused.
// LeafForward122d660, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x122d660 LeafForward122d660::Forward
#include "LeafForward122d660.h"
extern "C" void* leaf_target(void*);
void* LeafForward122d660::Forward() { return leaf_target(this); }
