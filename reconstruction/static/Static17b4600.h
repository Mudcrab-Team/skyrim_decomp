// Source exposure: binary-analysis; no external implementation source reused.
// Static17b4600, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17b4600;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17b4600*);
    virtual void release(Static17b4600*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17b4600*);
struct Static17b4600 {
    void* value;
    Static17b4600();
    ~Static17b4600() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
