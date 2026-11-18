// Source exposure: binary-analysis
// Static1084e0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1084e0;
extern void construct(Static1084e0*, const Descriptor*);
extern void destroy(Static1084e0*);
struct Static1084e0 {
    void* value;
    Static1084e0() { construct(this, &descriptor); }
    ~Static1084e0() { destroy(this); }
};
