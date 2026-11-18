// Source exposure: binary-analysis; no external implementation source reused.
// Static1761a10, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1761a10;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1761a10*);
    virtual void release(Static1761a10*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1761a10*);
struct Static1761a10 {
    void* value;
    Static1761a10();
    ~Static1761a10() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
