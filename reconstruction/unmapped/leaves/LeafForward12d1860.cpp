// Source exposure: binary-analysis; no external implementation reused.
// LeafForward12d1860, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x12d1860 LeafForward12d1860::Forward
#include "LeafForward12d1860.h"
extern "C" void* leaf_target(void*);
void* LeafForward12d1860::Forward() { return leaf_target(this); }
