// Source exposure: binary-analysis
// Static97de0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static97de0;
extern void construct(Static97de0*, const Descriptor*);
extern void destroy(Static97de0*);
struct Static97de0 {
    void* value;
    Static97de0() { construct(this, &descriptor); }
    ~Static97de0() { destroy(this); }
};
