// Source exposure: binary-analysis
// Static886d0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static886d0;
extern void construct(Static886d0*, const Descriptor*);
extern void destroy(Static886d0*);
struct Static886d0 {
    void* value;
    Static886d0() { construct(this, &descriptor); }
    ~Static886d0() { destroy(this); }
};
