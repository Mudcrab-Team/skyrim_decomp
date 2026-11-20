// Source exposure: binary-analysis; no external implementation reused.
// LeafForward85eea0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x85eea0 LeafForward85eea0::Forward
#include "LeafForward85eea0.h"
extern "C" void* leaf_target(void*);
void* LeafForward85eea0::Forward() { return leaf_target(this); }
