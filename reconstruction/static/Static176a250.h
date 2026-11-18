// Source exposure: binary-analysis; no external implementation source reused.
// Static176a250, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176a250;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176a250*);
    virtual void release(Static176a250*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176a250*);
struct Static176a250 {
    void* value;
    Static176a250();
    ~Static176a250() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
