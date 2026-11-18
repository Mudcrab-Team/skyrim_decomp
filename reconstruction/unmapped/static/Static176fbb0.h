// Source exposure: binary-analysis; no external implementation source reused.
// Static176fbb0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176fbb0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176fbb0*);
    virtual void release(Static176fbb0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176fbb0*);
struct Static176fbb0 {
    void* value;
    Static176fbb0();
    ~Static176fbb0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
