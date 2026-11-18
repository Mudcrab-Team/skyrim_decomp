// Source exposure: binary-analysis
// Staticb75a0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb75a0;
extern void construct(Staticb75a0*, const Descriptor*);
extern void destroy(Staticb75a0*);
struct Staticb75a0 {
    void* value;
    Staticb75a0() { construct(this, &descriptor); }
    ~Staticb75a0() { destroy(this); }
};
