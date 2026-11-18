// Source exposure: binary-analysis; no external implementation source reused.
// Static17aa240, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17aa240;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17aa240*);
    virtual void release(Static17aa240*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17aa240*);
struct Static17aa240 {
    void* value;
    Static17aa240();
    ~Static17aa240() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
