// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardcb1a60, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xcb1a60 LeafForwardcb1a60::Forward
#include "LeafForwardcb1a60.h"
extern "C" void* leaf_target(void*);
void* LeafForwardcb1a60::Forward() { return leaf_target(this); }
