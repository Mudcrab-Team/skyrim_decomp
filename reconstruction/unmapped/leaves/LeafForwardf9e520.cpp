// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf9e520, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf9e520 LeafForwardf9e520::Forward
#include "LeafForwardf9e520.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf9e520::Forward() { return leaf_target(this); }
