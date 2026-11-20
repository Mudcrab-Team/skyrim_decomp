// Source exposure: binary-analysis; no external implementation source reused.
// Static1747030, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1747030;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1747030*);
    virtual void release(Static1747030*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1747030*);
struct Static1747030 {
    void* value;
    Static1747030();
    ~Static1747030() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
