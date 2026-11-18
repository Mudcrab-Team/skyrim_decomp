// Source exposure: binary-analysis; no external implementation reused.
// LeafForward836270, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x836270 LeafForward836270::Forward
#include "LeafForward836270.h"
extern "C" void* leaf_target(void*);
void* LeafForward836270::Forward() { return leaf_target(this); }
