// Source exposure: binary-analysis; no external implementation source reused.
// Static17b7940, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17b7940;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17b7940*);
    virtual void release(Static17b7940*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17b7940*);
struct Static17b7940 {
    void* value;
    Static17b7940();
    ~Static17b7940() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
