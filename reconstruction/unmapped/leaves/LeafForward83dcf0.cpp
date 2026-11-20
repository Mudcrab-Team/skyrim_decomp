// Source exposure: binary-analysis; no external implementation reused.
// LeafForward83dcf0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x83dcf0 LeafForward83dcf0::Forward
#include "LeafForward83dcf0.h"
extern "C" void* leaf_target(void*);
void* LeafForward83dcf0::Forward() { return leaf_target(this); }
