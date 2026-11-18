// Source exposure: binary-analysis; no external implementation source reused.
// Static1759540, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1759540;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1759540*);
    virtual void release(Static1759540*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1759540*);
struct Static1759540 {
    void* value;
    Static1759540();
    ~Static1759540() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
