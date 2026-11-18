// Source exposure: binary-analysis; no external implementation source reused.
// Static176dcc0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176dcc0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176dcc0*);
    virtual void release(Static176dcc0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176dcc0*);
struct Static176dcc0 {
    void* value;
    Static176dcc0();
    ~Static176dcc0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
