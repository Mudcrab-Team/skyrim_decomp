// Source exposure: binary-analysis; no external implementation source reused.
// Static174ae40, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174ae40;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174ae40*);
    virtual void release(Static174ae40*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174ae40*);
struct Static174ae40 {
    void* value;
    Static174ae40();
    ~Static174ae40() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
