// Source exposure: binary-analysis; no external implementation source reused.
// Static174f950, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174f950;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174f950*);
    virtual void release(Static174f950*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174f950*);
struct Static174f950 {
    void* value;
    Static174f950();
    ~Static174f950() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
