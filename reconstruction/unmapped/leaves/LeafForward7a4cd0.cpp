// Source exposure: binary-analysis; no external implementation reused.
// LeafForward7a4cd0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x7a4cd0 LeafForward7a4cd0::Forward
#include "LeafForward7a4cd0.h"
extern "C" void* leaf_target(void*);
void* LeafForward7a4cd0::Forward() { return leaf_target(this); }
