// Source exposure: binary-analysis; no external implementation source reused.
// Static17b8150, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17b8150;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17b8150*);
    virtual void release(Static17b8150*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17b8150*);
struct Static17b8150 {
    void* value;
    Static17b8150();
    ~Static17b8150() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
