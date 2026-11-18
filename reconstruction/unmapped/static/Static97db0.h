// Source exposure: binary-analysis
// Static97db0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static97db0;
extern void construct(Static97db0*, const Descriptor*);
extern void destroy(Static97db0*);
struct Static97db0 {
    void* value;
    Static97db0() { construct(this, &descriptor); }
    ~Static97db0() { destroy(this); }
};
