// Source exposure: binary-analysis; no external implementation source reused.
// Static17c2570, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17c2570;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17c2570*);
    virtual void release(Static17c2570*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17c2570*);
struct Static17c2570 {
    void* value;
    Static17c2570();
    ~Static17c2570() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
