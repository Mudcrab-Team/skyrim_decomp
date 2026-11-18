// Source exposure: binary-analysis
// Staticb5160, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb5160;
extern void construct(Staticb5160*, const Descriptor*);
extern void destroy(Staticb5160*);
struct Staticb5160 {
    void* value;
    Staticb5160() { construct(this, &descriptor); }
    ~Staticb5160() { destroy(this); }
};
