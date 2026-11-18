// Source exposure: binary-analysis; no external implementation reused.
// LeafForward5c5890, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x5c5890 LeafForward5c5890::Forward
#include "LeafForward5c5890.h"
extern "C" void* leaf_target(void*);
void* LeafForward5c5890::Forward() { return leaf_target(this); }
