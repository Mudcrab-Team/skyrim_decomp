// Source exposure: binary-analysis; no external implementation source reused.
// Static1754540, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1754540;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1754540*);
    virtual void release(Static1754540*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1754540*);
struct Static1754540 {
    void* value;
    Static1754540();
    ~Static1754540() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
