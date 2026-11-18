// Source exposure: binary-analysis; no external implementation source reused.
// Static173dd80, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173dd80;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173dd80*);
    virtual void release(Static173dd80*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173dd80*);
struct Static173dd80 {
    void* value;
    Static173dd80();
    ~Static173dd80() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
