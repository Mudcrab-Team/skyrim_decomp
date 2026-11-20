// Source exposure: binary-analysis; no external implementation source reused.
// Static177ca40, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177ca40;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177ca40*);
    virtual void release(Static177ca40*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177ca40*);
struct Static177ca40 {
    void* value;
    Static177ca40();
    ~Static177ca40() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
