// Source exposure: binary-analysis; no external implementation source reused.
// Static1748920, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1748920;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1748920*);
    virtual void release(Static1748920*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1748920*);
struct Static1748920 {
    void* value;
    Static1748920();
    ~Static1748920() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
