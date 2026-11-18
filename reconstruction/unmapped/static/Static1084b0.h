// Source exposure: binary-analysis
// Static1084b0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1084b0;
extern void construct(Static1084b0*, const Descriptor*);
extern void destroy(Static1084b0*);
struct Static1084b0 {
    void* value;
    Static1084b0() { construct(this, &descriptor); }
    ~Static1084b0() { destroy(this); }
};
