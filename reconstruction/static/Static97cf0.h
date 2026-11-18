// Source exposure: binary-analysis
// Static97cf0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static97cf0;
extern void construct(Static97cf0*, const Descriptor*);
extern void destroy(Static97cf0*);
struct Static97cf0 {
    void* value;
    Static97cf0() { construct(this, &descriptor); }
    ~Static97cf0() { destroy(this); }
};
