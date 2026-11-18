// Source exposure: binary-analysis
// Staticb9aa0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb9aa0;
extern void construct(Staticb9aa0*, const Descriptor*);
extern void destroy(Staticb9aa0*);
struct Staticb9aa0 {
    void* value;
    Staticb9aa0() { construct(this, &descriptor); }
    ~Staticb9aa0() { destroy(this); }
};
