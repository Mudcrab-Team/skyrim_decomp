// Source exposure: binary-analysis; no external implementation source reused.
// Static179dbb0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179dbb0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179dbb0*);
    virtual void release(Static179dbb0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179dbb0*);
struct Static179dbb0 {
    void* value;
    Static179dbb0();
    ~Static179dbb0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
