// Source exposure: binary-analysis; no external implementation source reused.
// Static1753370, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1753370;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1753370*);
    virtual void release(Static1753370*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1753370*);
struct Static1753370 {
    void* value;
    Static1753370();
    ~Static1753370() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
