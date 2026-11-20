// Source exposure: binary-analysis; no external implementation source reused.
// Static17b5780, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17b5780;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17b5780*);
    virtual void release(Static17b5780*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17b5780*);
struct Static17b5780 {
    void* value;
    Static17b5780();
    ~Static17b5780() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
