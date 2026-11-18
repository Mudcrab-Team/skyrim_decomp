// Source exposure: binary-analysis
// Staticb3dd0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb3dd0;
extern void construct(Staticb3dd0*, const Descriptor*);
extern void destroy(Staticb3dd0*);
struct Staticb3dd0 {
    void* value;
    Staticb3dd0() { construct(this, &descriptor); }
    ~Staticb3dd0() { destroy(this); }
};
