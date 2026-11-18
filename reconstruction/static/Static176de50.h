// Source exposure: binary-analysis; no external implementation source reused.
// Static176de50, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176de50;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176de50*);
    virtual void release(Static176de50*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176de50*);
struct Static176de50 {
    void* value;
    Static176de50();
    ~Static176de50() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
