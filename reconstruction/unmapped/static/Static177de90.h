// Source exposure: binary-analysis; no external implementation source reused.
// Static177de90, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177de90;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177de90*);
    virtual void release(Static177de90*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177de90*);
struct Static177de90 {
    void* value;
    Static177de90();
    ~Static177de90() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
