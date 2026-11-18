// Source exposure: binary-analysis; no external implementation source reused.
// Static174bbb0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174bbb0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174bbb0*);
    virtual void release(Static174bbb0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174bbb0*);
struct Static174bbb0 {
    void* value;
    Static174bbb0();
    ~Static174bbb0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
