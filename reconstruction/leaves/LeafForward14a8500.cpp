// Source exposure: binary-analysis; no external implementation reused.
// LeafForward14a8500, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x14a8500 LeafForward14a8500::Forward
#include "LeafForward14a8500.h"
extern "C" void* leaf_target(void*);
void* LeafForward14a8500::Forward() { return leaf_target(this); }
