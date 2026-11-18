// Source exposure: binary-analysis; no external implementation source reused.
// Static17a8540, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17a8540;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17a8540*);
    virtual void release(Static17a8540*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17a8540*);
struct Static17a8540 {
    void* value;
    Static17a8540();
    ~Static17a8540() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
