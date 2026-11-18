// Source exposure: binary-analysis; no external implementation source reused.
// Static1752510, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1752510;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1752510*);
    virtual void release(Static1752510*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1752510*);
struct Static1752510 {
    void* value;
    Static1752510();
    ~Static1752510() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
