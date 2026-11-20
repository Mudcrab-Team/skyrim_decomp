// Source exposure: binary-analysis; no external implementation reused.
// LeafForward153b230, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x153b230 LeafForward153b230::Forward
#include "LeafForward153b230.h"
extern "C" void* leaf_target(void*);
void* LeafForward153b230::Forward() { return leaf_target(this); }
