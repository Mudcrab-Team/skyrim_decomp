// Source exposure: binary-analysis; no external implementation source reused.
// Static1775920, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1775920;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1775920*);
    virtual void release(Static1775920*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1775920*);
struct Static1775920 {
    void* value;
    Static1775920();
    ~Static1775920() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
