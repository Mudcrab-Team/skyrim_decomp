// Source exposure: binary-analysis; no external implementation source reused.
// Static1752a10, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1752a10;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1752a10*);
    virtual void release(Static1752a10*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1752a10*);
struct Static1752a10 {
    void* value;
    Static1752a10();
    ~Static1752a10() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
