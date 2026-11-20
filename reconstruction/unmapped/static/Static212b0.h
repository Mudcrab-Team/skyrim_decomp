// Source exposure: binary-analysis
// Static212b0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static212b0;
extern void construct(Static212b0*, const Descriptor*);
extern void destroy(Static212b0*);
struct Static212b0 {
    void* value;
    Static212b0() { construct(this, &descriptor); }
    ~Static212b0() { destroy(this); }
};
