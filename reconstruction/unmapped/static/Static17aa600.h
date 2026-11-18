// Source exposure: binary-analysis; no external implementation source reused.
// Static17aa600, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17aa600;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17aa600*);
    virtual void release(Static17aa600*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17aa600*);
struct Static17aa600 {
    void* value;
    Static17aa600();
    ~Static17aa600() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
