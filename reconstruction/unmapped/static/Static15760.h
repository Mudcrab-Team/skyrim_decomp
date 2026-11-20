// Source exposure: binary-analysis
// Static15760, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static15760;
extern void construct(Static15760*, const Descriptor*);
extern void destroy(Static15760*);
struct Static15760 {
    void* value;
    Static15760() { construct(this, &descriptor); }
    ~Static15760() { destroy(this); }
};
