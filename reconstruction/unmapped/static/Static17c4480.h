// Source exposure: binary-analysis; no external implementation source reused.
// Static17c4480, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17c4480;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17c4480*);
    virtual void release(Static17c4480*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17c4480*);
struct Static17c4480 {
    void* value;
    Static17c4480();
    ~Static17c4480() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
