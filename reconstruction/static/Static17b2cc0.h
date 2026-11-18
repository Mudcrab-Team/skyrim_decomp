// Source exposure: binary-analysis; no external implementation source reused.
// Static17b2cc0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17b2cc0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17b2cc0*);
    virtual void release(Static17b2cc0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17b2cc0*);
struct Static17b2cc0 {
    void* value;
    Static17b2cc0();
    ~Static17b2cc0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
