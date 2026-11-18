// Source exposure: binary-analysis; no external implementation source reused.
// Static1766a10, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1766a10;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1766a10*);
    virtual void release(Static1766a10*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1766a10*);
struct Static1766a10 {
    void* value;
    Static1766a10();
    ~Static1766a10() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
