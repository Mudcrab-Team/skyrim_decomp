// Source exposure: binary-analysis; no external implementation reused.
// LeafForward157dfa0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x157dfa0 LeafForward157dfa0::Forward
#include "LeafForward157dfa0.h"
extern "C" void* leaf_target(void*);
void* LeafForward157dfa0::Forward() { return leaf_target(this); }
