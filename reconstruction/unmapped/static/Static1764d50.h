// Source exposure: binary-analysis; no external implementation source reused.
// Static1764d50, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1764d50;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1764d50*);
    virtual void release(Static1764d50*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1764d50*);
struct Static1764d50 {
    void* value;
    Static1764d50();
    ~Static1764d50() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
