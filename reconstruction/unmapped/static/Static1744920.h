// Source exposure: binary-analysis; no external implementation source reused.
// Static1744920, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1744920;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1744920*);
    virtual void release(Static1744920*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1744920*);
struct Static1744920 {
    void* value;
    Static1744920();
    ~Static1744920() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
