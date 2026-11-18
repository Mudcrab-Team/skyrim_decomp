// Source exposure: binary-analysis
// Staticc5480, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticc5480;
extern void construct(Staticc5480*, const Descriptor*);
extern void destroy(Staticc5480*);
struct Staticc5480 {
    void* value;
    Staticc5480() { construct(this, &descriptor); }
    ~Staticc5480() { destroy(this); }
};
