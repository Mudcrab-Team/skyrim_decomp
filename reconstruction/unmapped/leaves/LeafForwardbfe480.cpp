// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardbfe480, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xbfe480 LeafForwardbfe480::Forward
#include "LeafForwardbfe480.h"
extern "C" void* leaf_target(void*);
void* LeafForwardbfe480::Forward() { return leaf_target(this); }
