// Source exposure: binary-analysis; no external implementation source reused.
// Static177ca90, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177ca90;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177ca90*);
    virtual void release(Static177ca90*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177ca90*);
struct Static177ca90 {
    void* value;
    Static177ca90();
    ~Static177ca90() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
