// Source exposure: binary-analysis; no external implementation source reused.
// Static17c6c80, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17c6c80;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17c6c80*);
    virtual void release(Static17c6c80*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17c6c80*);
struct Static17c6c80 {
    void* value;
    Static17c6c80();
    ~Static17c6c80() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
