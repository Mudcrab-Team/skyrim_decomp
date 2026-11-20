// Source exposure: binary-analysis; no external implementation reused.
// LeafForward128ec60, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x128ec60 LeafForward128ec60::Forward
#include "LeafForward128ec60.h"
extern "C" void* leaf_target(void*);
void* LeafForward128ec60::Forward() { return leaf_target(this); }
