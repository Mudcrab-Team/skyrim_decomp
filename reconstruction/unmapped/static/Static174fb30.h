// Source exposure: binary-analysis; no external implementation source reused.
// Static174fb30, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174fb30;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174fb30*);
    virtual void release(Static174fb30*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174fb30*);
struct Static174fb30 {
    void* value;
    Static174fb30();
    ~Static174fb30() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
