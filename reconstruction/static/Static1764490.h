// Source exposure: binary-analysis; no external implementation source reused.
// Static1764490, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1764490;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1764490*);
    virtual void release(Static1764490*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1764490*);
struct Static1764490 {
    void* value;
    Static1764490();
    ~Static1764490() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
