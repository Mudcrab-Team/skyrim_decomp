// Source exposure: binary-analysis
// Staticb5b80, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb5b80;
extern void construct(Staticb5b80*, const Descriptor*);
extern void destroy(Staticb5b80*);
struct Staticb5b80 {
    void* value;
    Staticb5b80() { construct(this, &descriptor); }
    ~Staticb5b80() { destroy(this); }
};
