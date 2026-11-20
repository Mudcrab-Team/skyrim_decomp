// Source exposure: binary-analysis
// Staticb7540, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb7540;
extern void construct(Staticb7540*, const Descriptor*);
extern void destroy(Staticb7540*);
struct Staticb7540 {
    void* value;
    Staticb7540() { construct(this, &descriptor); }
    ~Staticb7540() { destroy(this); }
};
