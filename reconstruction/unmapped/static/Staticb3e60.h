// Source exposure: binary-analysis
// Staticb3e60, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb3e60;
extern void construct(Staticb3e60*, const Descriptor*);
extern void destroy(Staticb3e60*);
struct Staticb3e60 {
    void* value;
    Staticb3e60() { construct(this, &descriptor); }
    ~Staticb3e60() { destroy(this); }
};
