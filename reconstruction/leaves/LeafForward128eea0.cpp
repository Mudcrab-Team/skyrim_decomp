// Source exposure: binary-analysis; no external implementation reused.
// LeafForward128eea0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x128eea0 LeafForward128eea0::Forward
#include "LeafForward128eea0.h"
extern "C" void* leaf_target(void*);
void* LeafForward128eea0::Forward() { return leaf_target(this); }
