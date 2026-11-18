// Source exposure: binary-analysis
// Static1ae90, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1ae90;
extern void construct(Static1ae90*, const Descriptor*);
extern void destroy(Static1ae90*);
struct Static1ae90 {
    void* value;
    Static1ae90() { construct(this, &descriptor); }
    ~Static1ae90() { destroy(this); }
};
