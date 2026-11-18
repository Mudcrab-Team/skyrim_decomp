// Source exposure: binary-analysis; no external implementation source reused.
// Static17add90, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17add90;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17add90*);
    virtual void release(Static17add90*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17add90*);
struct Static17add90 {
    void* value;
    Static17add90();
    ~Static17add90() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
