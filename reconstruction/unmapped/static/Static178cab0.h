// Source exposure: binary-analysis; no external implementation source reused.
// Static178cab0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178cab0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178cab0*);
    virtual void release(Static178cab0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178cab0*);
struct Static178cab0 {
    void* value;
    Static178cab0();
    ~Static178cab0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
