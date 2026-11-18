// Source exposure: binary-analysis; no external implementation source reused.
// Static17b4d80, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17b4d80;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17b4d80*);
    virtual void release(Static17b4d80*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17b4d80*);
struct Static17b4d80 {
    void* value;
    Static17b4d80();
    ~Static17b4d80() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
