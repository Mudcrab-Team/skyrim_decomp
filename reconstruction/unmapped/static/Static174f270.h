// Source exposure: binary-analysis; no external implementation source reused.
// Static174f270, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174f270;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174f270*);
    virtual void release(Static174f270*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174f270*);
struct Static174f270 {
    void* value;
    Static174f270();
    ~Static174f270() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
