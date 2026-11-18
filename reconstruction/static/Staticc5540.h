// Source exposure: binary-analysis
// Staticc5540, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticc5540;
extern void construct(Staticc5540*, const Descriptor*);
extern void destroy(Staticc5540*);
struct Staticc5540 {
    void* value;
    Staticc5540() { construct(this, &descriptor); }
    ~Staticc5540() { destroy(this); }
};
