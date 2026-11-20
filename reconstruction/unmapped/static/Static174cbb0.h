// Source exposure: binary-analysis; no external implementation source reused.
// Static174cbb0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174cbb0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174cbb0*);
    virtual void release(Static174cbb0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174cbb0*);
struct Static174cbb0 {
    void* value;
    Static174cbb0();
    ~Static174cbb0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
