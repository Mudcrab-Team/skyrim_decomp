// Source exposure: binary-analysis
// Staticbae30, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticbae30;
extern void construct(Staticbae30*, const Descriptor*);
extern void destroy(Staticbae30*);
struct Staticbae30 {
    void* value;
    Staticbae30() { construct(this, &descriptor); }
    ~Staticbae30() { destroy(this); }
};
