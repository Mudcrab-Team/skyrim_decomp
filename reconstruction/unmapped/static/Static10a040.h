// Source exposure: binary-analysis
// Static10a040, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static10a040;
extern void construct(Static10a040*, const Descriptor*);
extern void destroy(Static10a040*);
struct Static10a040 {
    void* value;
    Static10a040() { construct(this, &descriptor); }
    ~Static10a040() { destroy(this); }
};
