// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardcb9c70, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xcb9c70 LeafForwardcb9c70::Forward
#include "LeafForwardcb9c70.h"
extern "C" void* leaf_target(void*);
void* LeafForwardcb9c70::Forward() { return leaf_target(this); }
