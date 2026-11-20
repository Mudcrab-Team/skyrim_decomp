// Source exposure: binary-analysis; no external implementation source reused.
// Static1784920, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1784920;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1784920*);
    virtual void release(Static1784920*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1784920*);
struct Static1784920 {
    void* value;
    Static1784920();
    ~Static1784920() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
