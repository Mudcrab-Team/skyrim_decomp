// Source exposure: binary-analysis
// Static1d680, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1d680;
extern void construct(Static1d680*, const Descriptor*);
extern void destroy(Static1d680*);
struct Static1d680 {
    void* value;
    Static1d680() { construct(this, &descriptor); }
    ~Static1d680() { destroy(this); }
};
