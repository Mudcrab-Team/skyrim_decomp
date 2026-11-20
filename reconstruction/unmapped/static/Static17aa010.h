// Source exposure: binary-analysis; no external implementation source reused.
// Static17aa010, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17aa010;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17aa010*);
    virtual void release(Static17aa010*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17aa010*);
struct Static17aa010 {
    void* value;
    Static17aa010();
    ~Static17aa010() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
