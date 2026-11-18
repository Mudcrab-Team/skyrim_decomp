// Source exposure: binary-analysis
// Static1030a0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1030a0;
extern void construct(Static1030a0*, const Descriptor*);
extern void destroy(Static1030a0*);
struct Static1030a0 {
    void* value;
    Static1030a0() { construct(this, &descriptor); }
    ~Static1030a0() { destroy(this); }
};
