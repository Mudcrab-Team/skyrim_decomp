// Source exposure: binary-analysis
// Static1d950, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1d950;
extern void construct(Static1d950*, const Descriptor*);
extern void destroy(Static1d950*);
struct Static1d950 {
    void* value;
    Static1d950() { construct(this, &descriptor); }
    ~Static1d950() { destroy(this); }
};
