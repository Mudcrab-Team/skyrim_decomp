// Source exposure: binary-analysis
// Staticd540, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticd540;
extern void construct(Staticd540*, const Descriptor*);
extern void destroy(Staticd540*);
struct Staticd540 {
    void* value;
    Staticd540() { construct(this, &descriptor); }
    ~Staticd540() { destroy(this); }
};
