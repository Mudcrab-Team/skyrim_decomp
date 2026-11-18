// Source exposure: binary-analysis
// Static177a0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static177a0;
extern void construct(Static177a0*, const Descriptor*);
extern void destroy(Static177a0*);
struct Static177a0 {
    void* value;
    Static177a0() { construct(this, &descriptor); }
    ~Static177a0() { destroy(this); }
};
