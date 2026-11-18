// Source exposure: binary-analysis
// Staticb5a00, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb5a00;
extern void construct(Staticb5a00*, const Descriptor*);
extern void destroy(Staticb5a00*);
struct Staticb5a00 {
    void* value;
    Staticb5a00() { construct(this, &descriptor); }
    ~Staticb5a00() { destroy(this); }
};
