// Source exposure: binary-analysis; no external implementation reused.
// LeafForward7a9330, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x7a9330 LeafForward7a9330::Forward
#include "LeafForward7a9330.h"
extern "C" void* leaf_target(void*);
void* LeafForward7a9330::Forward() { return leaf_target(this); }
