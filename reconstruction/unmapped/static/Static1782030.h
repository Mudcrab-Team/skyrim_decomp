// Source exposure: binary-analysis; no external implementation source reused.
// Static1782030, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1782030;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1782030*);
    virtual void release(Static1782030*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1782030*);
struct Static1782030 {
    void* value;
    Static1782030();
    ~Static1782030() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
