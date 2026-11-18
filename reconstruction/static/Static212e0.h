// Source exposure: binary-analysis
// Static212e0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static212e0;
extern void construct(Static212e0*, const Descriptor*);
extern void destroy(Static212e0*);
struct Static212e0 {
    void* value;
    Static212e0() { construct(this, &descriptor); }
    ~Static212e0() { destroy(this); }
};
