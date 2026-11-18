// Source exposure: binary-analysis
// Static9abd0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9abd0;
extern void construct(Static9abd0*, const Descriptor*);
extern void destroy(Static9abd0*);
struct Static9abd0 {
    void* value;
    Static9abd0() { construct(this, &descriptor); }
    ~Static9abd0() { destroy(this); }
};
