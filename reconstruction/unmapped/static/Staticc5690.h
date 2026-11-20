// Source exposure: binary-analysis
// Staticc5690, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticc5690;
extern void construct(Staticc5690*, const Descriptor*);
extern void destroy(Staticc5690*);
struct Staticc5690 {
    void* value;
    Staticc5690() { construct(this, &descriptor); }
    ~Staticc5690() { destroy(this); }
};
