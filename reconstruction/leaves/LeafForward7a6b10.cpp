// Source exposure: binary-analysis; no external implementation reused.
// LeafForward7a6b10, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x7a6b10 LeafForward7a6b10::Forward
#include "LeafForward7a6b10.h"
extern "C" void* leaf_target(void*);
void* LeafForward7a6b10::Forward() { return leaf_target(this); }
