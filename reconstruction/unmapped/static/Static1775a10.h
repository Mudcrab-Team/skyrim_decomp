// Source exposure: binary-analysis; no external implementation source reused.
// Static1775a10, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1775a10;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1775a10*);
    virtual void release(Static1775a10*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1775a10*);
struct Static1775a10 {
    void* value;
    Static1775a10();
    ~Static1775a10() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
