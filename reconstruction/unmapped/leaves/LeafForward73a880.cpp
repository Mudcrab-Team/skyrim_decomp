// Source exposure: binary-analysis; no external implementation reused.
// LeafForward73a880, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x73a880 LeafForward73a880::Forward
#include "LeafForward73a880.h"
extern "C" void* leaf_target(void*);
void* LeafForward73a880::Forward() { return leaf_target(this); }
