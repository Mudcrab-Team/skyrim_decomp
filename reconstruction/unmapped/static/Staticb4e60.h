// Source exposure: binary-analysis
// Staticb4e60, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb4e60;
extern void construct(Staticb4e60*, const Descriptor*);
extern void destroy(Staticb4e60*);
struct Staticb4e60 {
    void* value;
    Staticb4e60() { construct(this, &descriptor); }
    ~Staticb4e60() { destroy(this); }
};
