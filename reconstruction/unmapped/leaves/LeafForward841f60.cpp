// Source exposure: binary-analysis; no external implementation reused.
// LeafForward841f60, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x841f60 LeafForward841f60::Forward
#include "LeafForward841f60.h"
extern "C" void* leaf_target(void*);
void* LeafForward841f60::Forward() { return leaf_target(this); }
