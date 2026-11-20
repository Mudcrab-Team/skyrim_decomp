// Source exposure: binary-analysis; no external implementation reused.
// LeafForwarda0c310, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xa0c310 LeafForwarda0c310::Forward
#include "LeafForwarda0c310.h"
extern "C" void* leaf_target(void*);
void* LeafForwarda0c310::Forward() { return leaf_target(this); }
