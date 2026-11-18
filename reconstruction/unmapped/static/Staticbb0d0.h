// Source exposure: binary-analysis
// Staticbb0d0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticbb0d0;
extern void construct(Staticbb0d0*, const Descriptor*);
extern void destroy(Staticbb0d0*);
struct Staticbb0d0 {
    void* value;
    Staticbb0d0() { construct(this, &descriptor); }
    ~Staticbb0d0() { destroy(this); }
};
