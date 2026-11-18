// Source exposure: binary-analysis; no external implementation reused.
// LeafForward7eb230, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x7eb230 LeafForward7eb230::Forward
#include "LeafForward7eb230.h"
extern "C" void* leaf_target(void*);
void* LeafForward7eb230::Forward() { return leaf_target(this); }
