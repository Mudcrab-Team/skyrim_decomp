// Source exposure: binary-analysis
// Static243b0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static243b0;
extern void construct(Static243b0*, const Descriptor*);
extern void destroy(Static243b0*);
struct Static243b0 {
    void* value;
    Static243b0() { construct(this, &descriptor); }
    ~Static243b0() { destroy(this); }
};
