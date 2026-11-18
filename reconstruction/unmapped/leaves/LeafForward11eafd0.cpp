// Source exposure: binary-analysis; no external implementation reused.
// LeafForward11eafd0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x11eafd0 LeafForward11eafd0::Forward
#include "LeafForward11eafd0.h"
extern "C" void* leaf_target(void*);
void* LeafForward11eafd0::Forward() { return leaf_target(this); }
