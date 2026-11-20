// Source exposure: binary-analysis
// Static24290, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static24290;
extern void construct(Static24290*, const Descriptor*);
extern void destroy(Static24290*);
struct Static24290 {
    void* value;
    Static24290() { construct(this, &descriptor); }
    ~Static24290() { destroy(this); }
};
