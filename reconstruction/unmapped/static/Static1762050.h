// Source exposure: binary-analysis; no external implementation source reused.
// Static1762050, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1762050;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1762050*);
    virtual void release(Static1762050*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1762050*);
struct Static1762050 {
    void* value;
    Static1762050();
    ~Static1762050() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
