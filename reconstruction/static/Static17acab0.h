// Source exposure: binary-analysis; no external implementation source reused.
// Static17acab0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17acab0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17acab0*);
    virtual void release(Static17acab0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17acab0*);
struct Static17acab0 {
    void* value;
    Static17acab0();
    ~Static17acab0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
