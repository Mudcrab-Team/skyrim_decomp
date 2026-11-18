// Source exposure: binary-analysis; no external implementation reused.
// LeafForward841cc0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x841cc0 LeafForward841cc0::Forward
#include "LeafForward841cc0.h"
extern "C" void* leaf_target(void*);
void* LeafForward841cc0::Forward() { return leaf_target(this); }
