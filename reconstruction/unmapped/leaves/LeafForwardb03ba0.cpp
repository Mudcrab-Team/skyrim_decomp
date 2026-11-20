// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardb03ba0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xb03ba0 LeafForwardb03ba0::Forward
#include "LeafForwardb03ba0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardb03ba0::Forward() { return leaf_target(this); }
