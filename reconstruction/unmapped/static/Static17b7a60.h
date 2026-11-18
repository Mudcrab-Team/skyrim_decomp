// Source exposure: binary-analysis; no external implementation source reused.
// Static17b7a60, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17b7a60;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17b7a60*);
    virtual void release(Static17b7a60*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17b7a60*);
struct Static17b7a60 {
    void* value;
    Static17b7a60();
    ~Static17b7a60() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
