// Source exposure: binary-analysis
// Staticb7a60, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb7a60;
extern void construct(Staticb7a60*, const Descriptor*);
extern void destroy(Staticb7a60*);
struct Staticb7a60 {
    void* value;
    Staticb7a60() { construct(this, &descriptor); }
    ~Staticb7a60() { destroy(this); }
};
