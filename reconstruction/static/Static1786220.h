// Source exposure: binary-analysis; no external implementation source reused.
// Static1786220, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1786220;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1786220*);
    virtual void release(Static1786220*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1786220*);
struct Static1786220 {
    void* value;
    Static1786220();
    ~Static1786220() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
