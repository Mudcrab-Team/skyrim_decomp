// Source exposure: binary-analysis; no external implementation source reused.
// Static1762960, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1762960;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1762960*);
    virtual void release(Static1762960*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1762960*);
struct Static1762960 {
    void* value;
    Static1762960();
    ~Static1762960() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
