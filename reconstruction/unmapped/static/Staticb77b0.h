// Source exposure: binary-analysis
// Staticb77b0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb77b0;
extern void construct(Staticb77b0*, const Descriptor*);
extern void destroy(Staticb77b0*);
struct Staticb77b0 {
    void* value;
    Staticb77b0() { construct(this, &descriptor); }
    ~Staticb77b0() { destroy(this); }
};
