// Source exposure: binary-analysis
// Static1b430, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1b430;
extern void construct(Static1b430*, const Descriptor*);
extern void destroy(Static1b430*);
struct Static1b430 {
    void* value;
    Static1b430() { construct(this, &descriptor); }
    ~Static1b430() { destroy(this); }
};
