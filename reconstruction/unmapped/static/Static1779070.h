// Source exposure: binary-analysis; no external implementation source reused.
// Static1779070, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1779070;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1779070*);
    virtual void release(Static1779070*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1779070*);
struct Static1779070 {
    void* value;
    Static1779070();
    ~Static1779070() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
