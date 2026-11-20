// Source exposure: binary-analysis
// Static159a0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static159a0;
extern void construct(Static159a0*, const Descriptor*);
extern void destroy(Static159a0*);
struct Static159a0 {
    void* value;
    Static159a0() { construct(this, &descriptor); }
    ~Static159a0() { destroy(this); }
};
