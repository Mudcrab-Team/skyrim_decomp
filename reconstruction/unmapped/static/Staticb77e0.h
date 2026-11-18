// Source exposure: binary-analysis
// Staticb77e0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb77e0;
extern void construct(Staticb77e0*, const Descriptor*);
extern void destroy(Staticb77e0*);
struct Staticb77e0 {
    void* value;
    Staticb77e0() { construct(this, &descriptor); }
    ~Staticb77e0() { destroy(this); }
};
