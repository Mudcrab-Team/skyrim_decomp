// Source exposure: binary-analysis
// Static1d410, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1d410;
extern void construct(Static1d410*, const Descriptor*);
extern void destroy(Static1d410*);
struct Static1d410 {
    void* value;
    Static1d410() { construct(this, &descriptor); }
    ~Static1d410() { destroy(this); }
};
