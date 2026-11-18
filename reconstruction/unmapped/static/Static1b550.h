// Source exposure: binary-analysis
// Static1b550, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1b550;
extern void construct(Static1b550*, const Descriptor*);
extern void destroy(Static1b550*);
struct Static1b550 {
    void* value;
    Static1b550() { construct(this, &descriptor); }
    ~Static1b550() { destroy(this); }
};
