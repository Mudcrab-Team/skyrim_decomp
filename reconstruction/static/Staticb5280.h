// Source exposure: binary-analysis
// Staticb5280, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb5280;
extern void construct(Staticb5280*, const Descriptor*);
extern void destroy(Staticb5280*);
struct Staticb5280 {
    void* value;
    Staticb5280() { construct(this, &descriptor); }
    ~Staticb5280() { destroy(this); }
};
