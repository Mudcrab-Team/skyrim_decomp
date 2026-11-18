// Source exposure: binary-analysis
// Staticb5cd0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb5cd0;
extern void construct(Staticb5cd0*, const Descriptor*);
extern void destroy(Staticb5cd0*);
struct Staticb5cd0 {
    void* value;
    Staticb5cd0() { construct(this, &descriptor); }
    ~Staticb5cd0() { destroy(this); }
};
