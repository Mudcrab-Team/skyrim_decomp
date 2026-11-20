// Source exposure: binary-analysis; no external implementation source reused.
// Static1772130, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1772130;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1772130*);
    virtual void release(Static1772130*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1772130*);
struct Static1772130 {
    void* value;
    Static1772130();
    ~Static1772130() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
