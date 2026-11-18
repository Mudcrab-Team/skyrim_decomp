// Source exposure: binary-analysis
// Staticb7c10, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb7c10;
extern void construct(Staticb7c10*, const Descriptor*);
extern void destroy(Staticb7c10*);
struct Staticb7c10 {
    void* value;
    Staticb7c10() { construct(this, &descriptor); }
    ~Staticb7c10() { destroy(this); }
};
