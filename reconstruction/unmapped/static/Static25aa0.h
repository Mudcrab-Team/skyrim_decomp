// Source exposure: binary-analysis
// Static25aa0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static25aa0;
extern void construct(Static25aa0*, const Descriptor*);
extern void destroy(Static25aa0*);
struct Static25aa0 {
    void* value;
    Static25aa0() { construct(this, &descriptor); }
    ~Static25aa0() { destroy(this); }
};
