// Source exposure: binary-analysis
// Static883b0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static883b0;
extern void construct(Static883b0*, const Descriptor*);
extern void destroy(Static883b0*);
struct Static883b0 {
    void* value;
    Static883b0() { construct(this, &descriptor); }
    ~Static883b0() { destroy(this); }
};
