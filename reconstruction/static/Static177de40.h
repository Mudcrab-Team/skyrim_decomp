// Source exposure: binary-analysis; no external implementation source reused.
// Static177de40, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177de40;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177de40*);
    virtual void release(Static177de40*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177de40*);
struct Static177de40 {
    void* value;
    Static177de40();
    ~Static177de40() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
