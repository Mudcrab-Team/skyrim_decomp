// Source exposure: binary-analysis
// Static1ad70, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1ad70;
extern void construct(Static1ad70*, const Descriptor*);
extern void destroy(Static1ad70*);
struct Static1ad70 {
    void* value;
    Static1ad70() { construct(this, &descriptor); }
    ~Static1ad70() { destroy(this); }
};
