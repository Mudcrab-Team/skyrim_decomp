// Source exposure: binary-analysis; no external implementation source reused.
// Static173e550, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173e550;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173e550*);
    virtual void release(Static173e550*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173e550*);
struct Static173e550 {
    void* value;
    Static173e550();
    ~Static173e550() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
