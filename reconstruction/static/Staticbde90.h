// Source exposure: binary-analysis
// Staticbde90, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticbde90;
extern void construct(Staticbde90*, const Descriptor*);
extern void destroy(Staticbde90*);
struct Staticbde90 {
    void* value;
    Staticbde90() { construct(this, &descriptor); }
    ~Staticbde90() { destroy(this); }
};
