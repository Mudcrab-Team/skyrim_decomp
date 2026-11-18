// Source exposure: binary-analysis; no external implementation source reused.
// Static1761880, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1761880;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1761880*);
    virtual void release(Static1761880*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1761880*);
struct Static1761880 {
    void* value;
    Static1761880();
    ~Static1761880() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
