// Source exposure: binary-analysis
// Staticb7180, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb7180;
extern void construct(Staticb7180*, const Descriptor*);
extern void destroy(Staticb7180*);
struct Staticb7180 {
    void* value;
    Staticb7180() { construct(this, &descriptor); }
    ~Staticb7180() { destroy(this); }
};
