// Source exposure: binary-analysis
// Static23e40, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static23e40;
extern void construct(Static23e40*, const Descriptor*);
extern void destroy(Static23e40*);
struct Static23e40 {
    void* value;
    Static23e40() { construct(this, &descriptor); }
    ~Static23e40() { destroy(this); }
};
