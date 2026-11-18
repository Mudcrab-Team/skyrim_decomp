// Source exposure: binary-analysis; no external implementation reused.
// LeafForward15224e0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x15224e0 LeafForward15224e0::Forward
#include "LeafForward15224e0.h"
extern "C" void* leaf_target(void*);
void* LeafForward15224e0::Forward() { return leaf_target(this); }
