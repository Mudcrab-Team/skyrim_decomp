// Source exposure: binary-analysis
// Staticb9510, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb9510;
extern void construct(Staticb9510*, const Descriptor*);
extern void destroy(Staticb9510*);
struct Staticb9510 {
    void* value;
    Staticb9510() { construct(this, &descriptor); }
    ~Staticb9510() { destroy(this); }
};
