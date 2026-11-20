// Source exposure: binary-analysis; no external implementation source reused.
// Static1743930, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1743930;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1743930*);
    virtual void release(Static1743930*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1743930*);
struct Static1743930 {
    void* value;
    Static1743930();
    ~Static1743930() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
