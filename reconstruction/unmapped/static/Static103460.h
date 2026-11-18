// Source exposure: binary-analysis
// Static103460, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static103460;
extern void construct(Static103460*, const Descriptor*);
extern void destroy(Static103460*);
struct Static103460 {
    void* value;
    Static103460() { construct(this, &descriptor); }
    ~Static103460() { destroy(this); }
};
