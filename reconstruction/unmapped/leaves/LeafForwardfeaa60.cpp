// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfeaa60, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfeaa60 LeafForwardfeaa60::Forward
#include "LeafForwardfeaa60.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfeaa60::Forward() { return leaf_target(this); }
