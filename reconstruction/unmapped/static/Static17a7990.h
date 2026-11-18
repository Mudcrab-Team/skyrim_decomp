// Source exposure: binary-analysis; no external implementation source reused.
// Static17a7990, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17a7990;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17a7990*);
    virtual void release(Static17a7990*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17a7990*);
struct Static17a7990 {
    void* value;
    Static17a7990();
    ~Static17a7990() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
