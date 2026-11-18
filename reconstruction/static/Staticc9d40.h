// Source exposure: binary-analysis
// Staticc9d40, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticc9d40;
extern void construct(Staticc9d40*, const Descriptor*);
extern void destroy(Staticc9d40*);
struct Staticc9d40 {
    void* value;
    Staticc9d40() { construct(this, &descriptor); }
    ~Staticc9d40() { destroy(this); }
};
