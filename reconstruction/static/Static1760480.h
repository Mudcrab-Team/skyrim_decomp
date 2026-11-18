// Source exposure: binary-analysis; no external implementation source reused.
// Static1760480, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1760480;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1760480*);
    virtual void release(Static1760480*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1760480*);
struct Static1760480 {
    void* value;
    Static1760480();
    ~Static1760480() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
