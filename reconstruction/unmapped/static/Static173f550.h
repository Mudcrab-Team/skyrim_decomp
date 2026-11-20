// Source exposure: binary-analysis; no external implementation source reused.
// Static173f550, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173f550;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173f550*);
    virtual void release(Static173f550*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173f550*);
struct Static173f550 {
    void* value;
    Static173f550();
    ~Static173f550() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
