// Source exposure: binary-analysis; no external implementation source reused.
// Static1750170, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1750170;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1750170*);
    virtual void release(Static1750170*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1750170*);
struct Static1750170 {
    void* value;
    Static1750170();
    ~Static1750170() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
