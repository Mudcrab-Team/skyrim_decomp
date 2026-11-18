// Source exposure: binary-analysis; no external implementation reused.
// LeafForward849290, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x849290 LeafForward849290::Forward
#include "LeafForward849290.h"
extern "C" void* leaf_target(void*);
void* LeafForward849290::Forward() { return leaf_target(this); }
