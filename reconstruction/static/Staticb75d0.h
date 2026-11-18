// Source exposure: binary-analysis
// Staticb75d0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb75d0;
extern void construct(Staticb75d0*, const Descriptor*);
extern void destroy(Staticb75d0*);
struct Staticb75d0 {
    void* value;
    Staticb75d0() { construct(this, &descriptor); }
    ~Staticb75d0() { destroy(this); }
};
