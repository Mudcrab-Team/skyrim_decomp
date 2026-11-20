// Source exposure: binary-analysis; no external implementation source reused.
// Static17b1710, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17b1710;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17b1710*);
    virtual void release(Static17b1710*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17b1710*);
struct Static17b1710 {
    void* value;
    Static17b1710();
    ~Static17b1710() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
