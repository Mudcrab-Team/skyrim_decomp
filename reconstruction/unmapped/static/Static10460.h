// Source exposure: binary-analysis
// Static10460, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static10460;
extern void construct(Static10460*, const Descriptor*);
extern void destroy(Static10460*);
struct Static10460 {
    void* value;
    Static10460() { construct(this, &descriptor); }
    ~Static10460() { destroy(this); }
};
