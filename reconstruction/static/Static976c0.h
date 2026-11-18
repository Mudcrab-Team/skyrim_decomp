// Source exposure: binary-analysis
// Static976c0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static976c0;
extern void construct(Static976c0*, const Descriptor*);
extern void destroy(Static976c0*);
struct Static976c0 {
    void* value;
    Static976c0() { construct(this, &descriptor); }
    ~Static976c0() { destroy(this); }
};
