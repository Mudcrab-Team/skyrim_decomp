// Source exposure: binary-analysis
// Staticca3d0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticca3d0;
extern void construct(Staticca3d0*, const Descriptor*);
extern void destroy(Staticca3d0*);
struct Staticca3d0 {
    void* value;
    Staticca3d0() { construct(this, &descriptor); }
    ~Staticca3d0() { destroy(this); }
};
