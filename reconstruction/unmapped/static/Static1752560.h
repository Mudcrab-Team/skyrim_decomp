// Source exposure: binary-analysis; no external implementation source reused.
// Static1752560, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1752560;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1752560*);
    virtual void release(Static1752560*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1752560*);
struct Static1752560 {
    void* value;
    Static1752560();
    ~Static1752560() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
