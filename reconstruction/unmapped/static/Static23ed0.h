// Source exposure: binary-analysis
// Static23ed0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static23ed0;
extern void construct(Static23ed0*, const Descriptor*);
extern void destroy(Static23ed0*);
struct Static23ed0 {
    void* value;
    Static23ed0() { construct(this, &descriptor); }
    ~Static23ed0() { destroy(this); }
};
