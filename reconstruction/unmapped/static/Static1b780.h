// Source exposure: binary-analysis
// Static1b780, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1b780;
extern void construct(Static1b780*, const Descriptor*);
extern void destroy(Static1b780*);
struct Static1b780 {
    void* value;
    Static1b780() { construct(this, &descriptor); }
    ~Static1b780() { destroy(this); }
};
