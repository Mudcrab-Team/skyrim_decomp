// Source exposure: binary-analysis; no external implementation source reused.
// Static1767370, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1767370;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1767370*);
    virtual void release(Static1767370*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1767370*);
struct Static1767370 {
    void* value;
    Static1767370();
    ~Static1767370() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
