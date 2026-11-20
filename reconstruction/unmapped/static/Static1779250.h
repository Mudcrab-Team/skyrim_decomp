// Source exposure: binary-analysis; no external implementation source reused.
// Static1779250, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1779250;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1779250*);
    virtual void release(Static1779250*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1779250*);
struct Static1779250 {
    void* value;
    Static1779250();
    ~Static1779250() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
