// Source exposure: binary-analysis; no external implementation source reused.
// Static177c860, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177c860;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177c860*);
    virtual void release(Static177c860*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177c860*);
struct Static177c860 {
    void* value;
    Static177c860();
    ~Static177c860() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
