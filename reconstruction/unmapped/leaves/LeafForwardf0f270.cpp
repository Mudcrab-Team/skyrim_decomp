// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf0f270, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf0f270 LeafForwardf0f270::Forward
#include "LeafForwardf0f270.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf0f270::Forward() { return leaf_target(this); }
