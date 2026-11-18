// Source exposure: binary-analysis; no external implementation source reused.
// Static176de00, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176de00;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176de00*);
    virtual void release(Static176de00*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176de00*);
struct Static176de00 {
    void* value;
    Static176de00();
    ~Static176de00() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
