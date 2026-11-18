// Source exposure: binary-analysis
// Staticf11a0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticf11a0;
extern void construct(Staticf11a0*, const Descriptor*);
extern void destroy(Staticf11a0*);
struct Staticf11a0 {
    void* value;
    Staticf11a0() { construct(this, &descriptor); }
    ~Staticf11a0() { destroy(this); }
};
