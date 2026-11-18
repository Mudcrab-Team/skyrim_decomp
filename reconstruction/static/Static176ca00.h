// Source exposure: binary-analysis; no external implementation source reused.
// Static176ca00, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176ca00;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176ca00*);
    virtual void release(Static176ca00*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176ca00*);
struct Static176ca00 {
    void* value;
    Static176ca00();
    ~Static176ca00() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
