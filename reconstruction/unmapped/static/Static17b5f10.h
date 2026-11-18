// Source exposure: binary-analysis; no external implementation source reused.
// Static17b5f10, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17b5f10;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17b5f10*);
    virtual void release(Static17b5f10*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17b5f10*);
struct Static17b5f10 {
    void* value;
    Static17b5f10();
    ~Static17b5f10() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
