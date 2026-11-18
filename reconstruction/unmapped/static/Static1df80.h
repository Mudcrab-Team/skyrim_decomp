// Source exposure: binary-analysis
// Static1df80, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1df80;
extern void construct(Static1df80*, const Descriptor*);
extern void destroy(Static1df80*);
struct Static1df80 {
    void* value;
    Static1df80() { construct(this, &descriptor); }
    ~Static1df80() { destroy(this); }
};
