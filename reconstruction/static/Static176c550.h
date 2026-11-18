// Source exposure: binary-analysis; no external implementation source reused.
// Static176c550, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176c550;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176c550*);
    virtual void release(Static176c550*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176c550*);
struct Static176c550 {
    void* value;
    Static176c550();
    ~Static176c550() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
