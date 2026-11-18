// Source exposure: binary-analysis; no external implementation source reused.
// Static1769490, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1769490;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1769490*);
    virtual void release(Static1769490*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1769490*);
struct Static1769490 {
    void* value;
    Static1769490();
    ~Static1769490() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
