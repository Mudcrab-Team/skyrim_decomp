// Source exposure: binary-analysis; no external implementation source reused.
// Static1769030, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1769030;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1769030*);
    virtual void release(Static1769030*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1769030*);
struct Static1769030 {
    void* value;
    Static1769030();
    ~Static1769030() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
