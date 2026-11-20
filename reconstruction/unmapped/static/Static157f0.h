// Source exposure: binary-analysis
// Static157f0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static157f0;
extern void construct(Static157f0*, const Descriptor*);
extern void destroy(Static157f0*);
struct Static157f0 {
    void* value;
    Static157f0() { construct(this, &descriptor); }
    ~Static157f0() { destroy(this); }
};
