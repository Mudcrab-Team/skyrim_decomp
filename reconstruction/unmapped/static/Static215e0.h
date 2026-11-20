// Source exposure: binary-analysis
// Static215e0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static215e0;
extern void construct(Static215e0*, const Descriptor*);
extern void destroy(Static215e0*);
struct Static215e0 {
    void* value;
    Static215e0() { construct(this, &descriptor); }
    ~Static215e0() { destroy(this); }
};
