// Source exposure: binary-analysis; no external implementation reused.
// LeafForward9ed290, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x9ed290 LeafForward9ed290::Forward
#include "LeafForward9ed290.h"
extern "C" void* leaf_target(void*);
void* LeafForward9ed290::Forward() { return leaf_target(this); }
