// Source exposure: binary-analysis; no external implementation source reused.
// Static174f770, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174f770;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174f770*);
    virtual void release(Static174f770*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174f770*);
struct Static174f770 {
    void* value;
    Static174f770();
    ~Static174f770() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
