// Source exposure: binary-analysis
// Staticb5370, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb5370;
extern void construct(Staticb5370*, const Descriptor*);
extern void destroy(Staticb5370*);
struct Staticb5370 {
    void* value;
    Staticb5370() { construct(this, &descriptor); }
    ~Staticb5370() { destroy(this); }
};
