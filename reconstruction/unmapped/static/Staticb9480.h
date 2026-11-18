// Source exposure: binary-analysis
// Staticb9480, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb9480;
extern void construct(Staticb9480*, const Descriptor*);
extern void destroy(Staticb9480*);
struct Staticb9480 {
    void* value;
    Staticb9480() { construct(this, &descriptor); }
    ~Staticb9480() { destroy(this); }
};
