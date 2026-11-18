// Source exposure: binary-analysis
// Staticb7e10, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb7e10;
extern void construct(Staticb7e10*, const Descriptor*);
extern void destroy(Staticb7e10*);
struct Staticb7e10 {
    void* value;
    Staticb7e10() { construct(this, &descriptor); }
    ~Staticb7e10() { destroy(this); }
};
