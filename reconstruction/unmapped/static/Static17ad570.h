// Source exposure: binary-analysis; no external implementation source reused.
// Static17ad570, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17ad570;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17ad570*);
    virtual void release(Static17ad570*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17ad570*);
struct Static17ad570 {
    void* value;
    Static17ad570();
    ~Static17ad570() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
