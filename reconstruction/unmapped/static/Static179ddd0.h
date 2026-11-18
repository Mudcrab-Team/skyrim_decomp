// Source exposure: binary-analysis; no external implementation source reused.
// Static179ddd0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179ddd0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179ddd0*);
    virtual void release(Static179ddd0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179ddd0*);
struct Static179ddd0 {
    void* value;
    Static179ddd0();
    ~Static179ddd0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
