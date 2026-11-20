// Source exposure: binary-analysis
// Staticb4bf0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb4bf0;
extern void construct(Staticb4bf0*, const Descriptor*);
extern void destroy(Staticb4bf0*);
struct Staticb4bf0 {
    void* value;
    Staticb4bf0() { construct(this, &descriptor); }
    ~Staticb4bf0() { destroy(this); }
};
