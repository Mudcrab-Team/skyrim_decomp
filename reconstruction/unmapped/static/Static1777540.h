// Source exposure: binary-analysis; no external implementation source reused.
// Static1777540, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1777540;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1777540*);
    virtual void release(Static1777540*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1777540*);
struct Static1777540 {
    void* value;
    Static1777540();
    ~Static1777540() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
