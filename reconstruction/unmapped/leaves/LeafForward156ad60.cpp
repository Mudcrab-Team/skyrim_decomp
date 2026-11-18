// Source exposure: binary-analysis; no external implementation reused.
// LeafForward156ad60, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x156ad60 LeafForward156ad60::Forward
#include "LeafForward156ad60.h"
extern "C" void* leaf_target(void*);
void* LeafForward156ad60::Forward() { return leaf_target(this); }
