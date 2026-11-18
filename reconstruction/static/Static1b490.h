// Source exposure: binary-analysis
// Static1b490, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1b490;
extern void construct(Static1b490*, const Descriptor*);
extern void destroy(Static1b490*);
struct Static1b490 {
    void* value;
    Static1b490() { construct(this, &descriptor); }
    ~Static1b490() { destroy(this); }
};
