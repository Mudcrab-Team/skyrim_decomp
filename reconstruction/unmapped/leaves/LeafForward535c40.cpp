// Source exposure: binary-analysis; no external implementation reused.
// LeafForward535c40, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x535c40 LeafForward535c40::Forward
#include "LeafForward535c40.h"
extern "C" void* leaf_target(void*);
void* LeafForward535c40::Forward() { return leaf_target(this); }
