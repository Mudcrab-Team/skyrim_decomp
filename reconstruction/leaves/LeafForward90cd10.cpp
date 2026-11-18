// Source exposure: binary-analysis; no external implementation reused.
// LeafForward90cd10, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x90cd10 LeafForward90cd10::Forward
#include "LeafForward90cd10.h"
extern "C" void* leaf_target(void*);
void* LeafForward90cd10::Forward() { return leaf_target(this); }
