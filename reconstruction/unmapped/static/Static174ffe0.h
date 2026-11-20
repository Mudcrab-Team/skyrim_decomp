// Source exposure: binary-analysis; no external implementation source reused.
// Static174ffe0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174ffe0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174ffe0*);
    virtual void release(Static174ffe0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174ffe0*);
struct Static174ffe0 {
    void* value;
    Static174ffe0();
    ~Static174ffe0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
