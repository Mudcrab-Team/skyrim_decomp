// Source exposure: binary-analysis
// Staticb5e00, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb5e00;
extern void construct(Staticb5e00*, const Descriptor*);
extern void destroy(Staticb5e00*);
struct Staticb5e00 {
    void* value;
    Staticb5e00() { construct(this, &descriptor); }
    ~Staticb5e00() { destroy(this); }
};
