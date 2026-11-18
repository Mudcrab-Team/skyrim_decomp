// Source exposure: binary-analysis; no external implementation source reused.
// Static176cdc0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176cdc0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176cdc0*);
    virtual void release(Static176cdc0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176cdc0*);
struct Static176cdc0 {
    void* value;
    Static176cdc0();
    ~Static176cdc0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
