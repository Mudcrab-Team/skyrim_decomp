// Source exposure: binary-analysis
// Staticb83d0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb83d0;
extern void construct(Staticb83d0*, const Descriptor*);
extern void destroy(Staticb83d0*);
struct Staticb83d0 {
    void* value;
    Staticb83d0() { construct(this, &descriptor); }
    ~Staticb83d0() { destroy(this); }
};
