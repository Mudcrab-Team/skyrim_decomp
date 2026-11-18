// Source exposure: binary-analysis; no external implementation source reused.
// Static17a4040, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17a4040;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17a4040*);
    virtual void release(Static17a4040*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17a4040*);
struct Static17a4040 {
    void* value;
    Static17a4040();
    ~Static17a4040() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
