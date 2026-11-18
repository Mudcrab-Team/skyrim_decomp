// Source exposure: binary-analysis; no external implementation reused.
// LeafForward8ea860, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x8ea860 LeafForward8ea860::Forward
#include "LeafForward8ea860.h"
extern "C" void* leaf_target(void*);
void* LeafForward8ea860::Forward() { return leaf_target(this); }
