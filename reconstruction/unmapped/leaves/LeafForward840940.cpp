// Source exposure: binary-analysis; no external implementation reused.
// LeafForward840940, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x840940 LeafForward840940::Forward
#include "LeafForward840940.h"
extern "C" void* leaf_target(void*);
void* LeafForward840940::Forward() { return leaf_target(this); }
