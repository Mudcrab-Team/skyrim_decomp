// Source exposure: binary-analysis; no external implementation reused.
// LeafForward14c7920, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x14c7920 LeafForward14c7920::Forward
#include "LeafForward14c7920.h"
extern "C" void* leaf_target(void*);
void* LeafForward14c7920::Forward() { return leaf_target(this); }
