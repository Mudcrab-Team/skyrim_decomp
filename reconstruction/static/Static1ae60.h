// Source exposure: binary-analysis
// Static1ae60, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1ae60;
extern void construct(Static1ae60*, const Descriptor*);
extern void destroy(Static1ae60*);
struct Static1ae60 {
    void* value;
    Static1ae60() { construct(this, &descriptor); }
    ~Static1ae60() { destroy(this); }
};
