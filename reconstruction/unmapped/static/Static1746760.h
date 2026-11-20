// Source exposure: binary-analysis; no external implementation source reused.
// Static1746760, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1746760;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1746760*);
    virtual void release(Static1746760*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1746760*);
struct Static1746760 {
    void* value;
    Static1746760();
    ~Static1746760() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
