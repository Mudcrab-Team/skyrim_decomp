// Source exposure: binary-analysis; no external implementation source reused.
// Static1769170, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1769170;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1769170*);
    virtual void release(Static1769170*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1769170*);
struct Static1769170 {
    void* value;
    Static1769170();
    ~Static1769170() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
