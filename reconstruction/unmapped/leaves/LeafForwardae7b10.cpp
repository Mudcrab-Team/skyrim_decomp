// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardae7b10, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xae7b10 LeafForwardae7b10::Forward
#include "LeafForwardae7b10.h"
extern "C" void* leaf_target(void*);
void* LeafForwardae7b10::Forward() { return leaf_target(this); }
