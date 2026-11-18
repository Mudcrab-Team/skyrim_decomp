// Source exposure: binary-analysis
// Staticbb0a0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticbb0a0;
extern void construct(Staticbb0a0*, const Descriptor*);
extern void destroy(Staticbb0a0*);
struct Staticbb0a0 {
    void* value;
    Staticbb0a0() { construct(this, &descriptor); }
    ~Staticbb0a0() { destroy(this); }
};
