// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfafcd0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfafcd0 LeafForwardfafcd0::Forward
#include "LeafForwardfafcd0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfafcd0::Forward() { return leaf_target(this); }
