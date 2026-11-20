// Source exposure: binary-analysis; no external implementation source reused.
// Static176aa20, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176aa20;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176aa20*);
    virtual void release(Static176aa20*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176aa20*);
struct Static176aa20 {
    void* value;
    Static176aa20();
    ~Static176aa20() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
