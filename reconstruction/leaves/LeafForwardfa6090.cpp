// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfa6090, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfa6090 LeafForwardfa6090::Forward
#include "LeafForwardfa6090.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfa6090::Forward() { return leaf_target(this); }
