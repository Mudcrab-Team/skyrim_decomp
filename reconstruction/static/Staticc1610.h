// Source exposure: binary-analysis
// Staticc1610, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticc1610;
extern void construct(Staticc1610*, const Descriptor*);
extern void destroy(Staticc1610*);
struct Staticc1610 {
    void* value;
    Staticc1610() { construct(this, &descriptor); }
    ~Staticc1610() { destroy(this); }
};
