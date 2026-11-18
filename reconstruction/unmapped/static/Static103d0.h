// Source exposure: binary-analysis
// Static103d0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static103d0;
extern void construct(Static103d0*, const Descriptor*);
extern void destroy(Static103d0*);
struct Static103d0 {
    void* value;
    Static103d0() { construct(this, &descriptor); }
    ~Static103d0() { destroy(this); }
};
