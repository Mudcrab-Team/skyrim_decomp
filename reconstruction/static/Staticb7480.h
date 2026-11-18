// Source exposure: binary-analysis
// Staticb7480, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb7480;
extern void construct(Staticb7480*, const Descriptor*);
extern void destroy(Staticb7480*);
struct Staticb7480 {
    void* value;
    Staticb7480() { construct(this, &descriptor); }
    ~Staticb7480() { destroy(this); }
};
