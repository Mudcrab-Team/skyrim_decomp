// Source exposure: binary-analysis; no external implementation source reused.
// Static176bb50, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176bb50;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176bb50*);
    virtual void release(Static176bb50*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176bb50*);
struct Static176bb50 {
    void* value;
    Static176bb50();
    ~Static176bb50() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
