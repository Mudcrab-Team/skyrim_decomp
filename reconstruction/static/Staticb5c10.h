// Source exposure: binary-analysis
// Staticb5c10, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb5c10;
extern void construct(Staticb5c10*, const Descriptor*);
extern void destroy(Staticb5c10*);
struct Staticb5c10 {
    void* value;
    Staticb5c10() { construct(this, &descriptor); }
    ~Staticb5c10() { destroy(this); }
};
