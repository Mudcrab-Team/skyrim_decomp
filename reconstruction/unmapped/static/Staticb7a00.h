// Source exposure: binary-analysis
// Staticb7a00, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb7a00;
extern void construct(Staticb7a00*, const Descriptor*);
extern void destroy(Staticb7a00*);
struct Staticb7a00 {
    void* value;
    Staticb7a00() { construct(this, &descriptor); }
    ~Staticb7a00() { destroy(this); }
};
