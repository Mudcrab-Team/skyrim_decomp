// Source exposure: binary-analysis
// Static1d650, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1d650;
extern void construct(Static1d650*, const Descriptor*);
extern void destroy(Static1d650*);
struct Static1d650 {
    void* value;
    Static1d650() { construct(this, &descriptor); }
    ~Static1d650() { destroy(this); }
};
