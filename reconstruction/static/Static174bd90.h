// Source exposure: binary-analysis; no external implementation source reused.
// Static174bd90, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174bd90;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174bd90*);
    virtual void release(Static174bd90*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174bd90*);
struct Static174bd90 {
    void* value;
    Static174bd90();
    ~Static174bd90() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
