// Source exposure: binary-analysis
// Staticb7390, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb7390;
extern void construct(Staticb7390*, const Descriptor*);
extern void destroy(Staticb7390*);
struct Staticb7390 {
    void* value;
    Staticb7390() { construct(this, &descriptor); }
    ~Staticb7390() { destroy(this); }
};
