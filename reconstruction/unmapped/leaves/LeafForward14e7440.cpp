// Source exposure: binary-analysis; no external implementation reused.
// LeafForward14e7440, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x14e7440 LeafForward14e7440::Forward
#include "LeafForward14e7440.h"
extern "C" void* leaf_target(void*);
void* LeafForward14e7440::Forward() { return leaf_target(this); }
