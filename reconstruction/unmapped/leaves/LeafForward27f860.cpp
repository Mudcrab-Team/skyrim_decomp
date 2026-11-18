// Source exposure: binary-analysis; no external implementation reused.
// LeafForward27f860, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x27f860 LeafForward27f860::Forward
#include "LeafForward27f860.h"
extern "C" void* leaf_target(void*);
void* LeafForward27f860::Forward() { return leaf_target(this); }
