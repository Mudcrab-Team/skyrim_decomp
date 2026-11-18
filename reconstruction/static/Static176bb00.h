// Source exposure: binary-analysis; no external implementation source reused.
// Static176bb00, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176bb00;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176bb00*);
    virtual void release(Static176bb00*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176bb00*);
struct Static176bb00 {
    void* value;
    Static176bb00();
    ~Static176bb00() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
