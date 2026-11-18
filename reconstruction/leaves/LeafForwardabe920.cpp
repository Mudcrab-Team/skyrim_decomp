// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardabe920, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xabe920 LeafForwardabe920::Forward
#include "LeafForwardabe920.h"
extern "C" void* leaf_target(void*);
void* LeafForwardabe920::Forward() { return leaf_target(this); }
