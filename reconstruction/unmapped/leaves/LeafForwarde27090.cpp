// Source exposure: binary-analysis; no external implementation reused.
// LeafForwarde27090, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xe27090 LeafForwarde27090::Forward
#include "LeafForwarde27090.h"
extern "C" void* leaf_target(void*);
void* LeafForwarde27090::Forward() { return leaf_target(this); }
