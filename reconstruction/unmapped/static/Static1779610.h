// Source exposure: binary-analysis; no external implementation source reused.
// Static1779610, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1779610;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1779610*);
    virtual void release(Static1779610*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1779610*);
struct Static1779610 {
    void* value;
    Static1779610();
    ~Static1779610() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
