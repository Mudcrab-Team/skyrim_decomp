// Source exposure: binary-analysis
// Staticb5d00, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb5d00;
extern void construct(Staticb5d00*, const Descriptor*);
extern void destroy(Staticb5d00*);
struct Staticb5d00 {
    void* value;
    Staticb5d00() { construct(this, &descriptor); }
    ~Staticb5d00() { destroy(this); }
};
