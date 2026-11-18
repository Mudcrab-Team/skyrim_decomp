// Source exposure: binary-analysis
// Staticb5e60, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb5e60;
extern void construct(Staticb5e60*, const Descriptor*);
extern void destroy(Staticb5e60*);
struct Staticb5e60 {
    void* value;
    Staticb5e60() { construct(this, &descriptor); }
    ~Staticb5e60() { destroy(this); }
};
