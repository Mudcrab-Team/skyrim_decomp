// Source exposure: binary-analysis
// Static1db00, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1db00;
extern void construct(Static1db00*, const Descriptor*);
extern void destroy(Static1db00*);
struct Static1db00 {
    void* value;
    Static1db00() { construct(this, &descriptor); }
    ~Static1db00() { destroy(this); }
};
