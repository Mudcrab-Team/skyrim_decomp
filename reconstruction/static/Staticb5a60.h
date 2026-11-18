// Source exposure: binary-analysis
// Staticb5a60, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb5a60;
extern void construct(Staticb5a60*, const Descriptor*);
extern void destroy(Staticb5a60*);
struct Staticb5a60 {
    void* value;
    Staticb5a60() { construct(this, &descriptor); }
    ~Staticb5a60() { destroy(this); }
};
